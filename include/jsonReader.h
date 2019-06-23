#include "json.hpp"
#include <iostream>
#include <cstddef>
#include <algorithm>
#include <fstream>
#include <string>
#include <memory>

#include "vec3.h"
#include "orthogonal_camera.h"
#include "perspective_camera.h"
#include "camera.h"
#include "sphere.h"
#include "primitive.h"
#include "primitive_list.h"
#include "plotter.h"
#include "integrator.h"
#include "sample_integrator.h"
#include "flat_integrator.h"
#include "depth_integrator.h"
#include "normal_integrator.h"


using json::JSON;
using namespace std;

typedef vec3 Color;
typedef vec3 Point;

string stringFromFile(string filename)
{
    //pega o arquivo e transforma em uma string pronta para ser convertida em objeto
    string aux;
    string userInput;
    ifstream infile;
    infile.open (filename);
        while(!infile.eof()){
            getline(infile,aux);
            userInput += aux;
        }
    infile.close();

    return userInput;
}

JSON parseFile(string filename){
    JSON obj;
    string userInput = stringFromFile(filename);
    obj = JSON::Load(userInput);
    return obj;
}

shared_ptr<Camera> cameraFromJSON(JSON obj){

    if (obj["camera"].IsNull()){
        std::cout<<"no instructions for camera in JSON file"<<std::endl;
        return nullptr;
    }else{
        string camParts[4] = {"origin","vertical","horizontal","corner"};
        vec3 aux[4];

        for(int i = 0; i < 4; i++){
            for(int j = 0;j < 3;j++){
                aux[i][j] = obj["camera"][camParts[i]][j].ToFloat();
            }
        }
        if(obj["camera"]["type"].ToString()=="orthogonal"){
            //warning for no direction instruction
            if (obj["camera"]["direction"].IsNull()){
                std::cout<<"no direction instruction for orthogonal camera"<<std::endl;
                return nullptr;
            }
            //warning for direction instruction without comma.
            float direction_input = obj["camera"]["direction"].ToFloat();
            if(direction_input == 0){
                std::cout<<"warning! direction read as 0, always write real numbers with commas"<<std::endl;
            }
            
            return make_shared<Orthogonal_camera>(aux[0],aux[1],aux[2],aux[3],direction_input);
        }else if(obj["camera"]["type"].ToString()=="perspective"){
            return make_shared<Perspective_camera>(aux[0],aux[1],aux[2],aux[3]);
        }else{
            std::cout<<"no instructions for camera type in JSON file"<<std::endl;
            return nullptr;
        }
    }
}

shared_ptr<Primitive_list> primitivesFromJSON(JSON obj, std::vector< shared_ptr<Material> > material_list){
    if (obj["primitives"].IsNull()){
        std::cout<<"no instructions for primitives in JSON file"<<std::endl;
        return nullptr;
    }else{


        int num_primitives = obj["primitives"].length();


        Primitive **list = new  Primitive*[num_primitives];

        Point aux;
        float radius;
        std::string material_name;
        shared_ptr<Material> aux_material;


        for(int i =0; i < num_primitives; i++){

            aux[0] = obj["primitives"][i][0].ToInt();
            aux[1] = obj["primitives"][i][1].ToInt();
            aux[2] = obj["primitives"][i][2].ToInt();

            radius = obj["primitives"][i][3].ToFloat();

            material_name = obj["primitives"][i][4].ToString();

            for(int i = 0;i < material_list.size();i++){
                if(material_name==material_list[i]->name){
                    aux_material = material_list[i];
                    break;
                }
            }

            list[i] = new Sphere(aux, radius, aux_material);
        }

        return make_shared<Primitive_list>(list, num_primitives);
    }
}

std::vector< shared_ptr<Material> > materialsFromJSON(JSON obj){
    if (obj["materials"].IsNull()){
        std::cout<<"no instructions for materials in JSON file"<<std::endl;
        return std::vector< shared_ptr<Material> > ();
    }else{
        int num_primitives = obj["materials"].length();


        std::vector< shared_ptr<Material> > material_list;

        Color aux;
        std::string aux_name;


        for(int i =0; i < num_primitives; i++){

            aux_name = obj["materials"][i][0].ToString();

            aux[0] = obj["materials"][i][1].ToInt();
            aux[1] = obj["materials"][i][2].ToInt();
            aux[2] = obj["materials"][i][3].ToInt();            

            shared_ptr<Material> to_add = make_shared<Material>(aux_name,Color(aux[0],aux[1],aux[2]));

            material_list.push_back(to_add);
        }

        return material_list;
    }

}

shared_ptr<Plotter> plotterFromJSON(JSON obj){
    if (obj["plotter"].IsNull()){
        std::cout<<"no instructions for plotter in JSON file"<<std::endl;
        return shared_ptr<Plotter> ();
    }else{
        int xSize   = obj["plotter"]["x"].ToInt();
        int ySize   = obj["plotter"]["y"].ToInt();
        string name = obj["plotter"]["name"].ToString();

        string file = "./imageOutput/" + name + ".ppm";

        return make_shared<Plotter>(xSize,ySize,file);
    }
}

shared_ptr<Background> backgroundFromJSON(JSON obj){
    int num_colors = obj["background"].length();
    Color aux_color;

    Color colors[4];

    for(int i = 0; i < num_colors; i++){
        aux_color[0] = obj["background"][i][0].ToInt();
        aux_color[1] = obj["background"][i][1].ToInt();
        aux_color[2] = obj["background"][i][2].ToInt();

        colors[i] = aux_color;
    }


    //repete as cores do interpolator se tiver menos que 4
    /*
    if(num_colors < 4 && num_colors > 0){
        for(int i = num_colors; i < 4; i++){
            colors[i] = colors[num_colors-1];
        }
    }
    */
    return make_shared<Background>(colors);
}

shared_ptr<Sample_integrator> integratorFromJSON(JSON obj, shared_ptr<Camera> cam){
    if (obj["integrator"].IsNull()){
        std::cout<<"no instructions for integrator in JSON file"<<std::endl;
        return nullptr;
    }else{


        if(obj["integrator"]["type"].ToString()=="flat"){
            return make_shared<Flat_integrator>(cam);
        }else if(obj["integrator"]["type"].ToString()=="normal"){
            return make_shared<Normal_integrator>(cam);
        }else if(obj["integrator"]["type"].ToString()=="depth"){
            Color near;
            Color far;

            if(obj["integrator"]["near"].IsNull() || obj["integrator"]["far"].IsNull() ){
                std::cout<<"no color assigned to near or to far, using Black and white"<<std::endl;

                near = Color (0,0,0);
                far  = Color (255,255,255);
            }else{
                int nr, ng, nb, fr, fg, fb;

                nr = obj["integrator"]["near"][0].ToInt();
                ng = obj["integrator"]["near"][1].ToInt();
                nb = obj["integrator"]["near"][2].ToInt();

                fr = obj["integrator"]["far"][0].ToInt();
                fg = obj["integrator"]["far"][1].ToInt();
                fb = obj["integrator"]["far"][2].ToInt();

                near = Color(nr, ng, nb);
                far  = Color(fr, fg, fb);
            }



            return make_shared<Depth_integrator>(cam,near,far);
        }else{
            std::cout<<"JSON integrator type not recognized"<<std::endl;
            return nullptr;
        }
    }
}