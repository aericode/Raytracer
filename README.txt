RAYTRACER

by: Eric Andrade

Note*: due to a problem with the JSON reader every real number should be written like "5.0" and not "5", as it causes them to be registered as 0. The real numbers are at the coordinates (camera and spehere) and at the sphere radius.

Compilation: open your terminal at the program's root folder and type "makefile"

Execution: type "./run" it will read the "./jsonInput/scene.json" file by default

JSON input:
	- Camera object
		needs to be named "camera"
		Subobjects:
			-"type": can be "orthogonal" or "perspective"
			origin: where is the center of the camera frame*
			horizontal: how wide is it.*
			vertical: how tall is it*
			corner: where is it's corner? (origin - horizontal/2 - vertical/2 for default operation)*
			direction (orthogonal only): what z direction do the rays go?*
	- Primitive list: (makes spheres with specified location, radius and material)
		needs to be named "primitives"
		Sublists
		[x, y, z, radius, material_name]*
		- Make lists with the coordinates, a number for radius and a material name to seek in the material list
	- Material list: Makes materials to add to the primitives
		needs to me named "materials"
		Sublist
		[material_name, r, g , b]
		- Create a material for you to add to your primitives
	- Plotter Object (Manages the output file)
		needs to be named "plotter"
		"x" : image height
		"y" : image width
		"name"	: output file name
	- Background list (interpolates 4 colors for the background)
		needs to be named "background"
		[r,g,b] put 4 colors like this
	- Integrator object
		Subobjects:
		"type": type of integrator, (flat, normal or depth)

		(Depth only)
		"near" : [r,g,b] objects become this color when close to you
		"far"  : [r,g,b] objects become this color when close to you

Generated image will be put at imageOutput, with the name specified at "Plotter"