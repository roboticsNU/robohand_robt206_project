import bpy
import mathutils

cube = bpy.data.objects["Cube"]
cone = bpy.data.objects["Cone"]
cube_i = cube.location.copy()
cone_i = cone.location.copy()
def moveCone(pos):
    # one blender unit in x-direction
    vec = mathutils.Vector((float(pos)/180.0 * 6.0, 0.0, 0.0))
    inv = cone.matrix_world.copy()
    inv.invert()
    vec_rot = vec * inv
    cone.location = cone_i + vec_rot

def moveCube(pos):
    # one blender unit in x-direction
    vec = mathutils.Vector((float(pos)/180.0 * 6.0, 0.0, 0.0))
    inv = cube.matrix_world.copy()
    inv.invert()
    vec_rot = vec * inv
    cube.location = cube_i + vec_rot

def MOVE():
    f = open("/Users/aidarbek/arduino_data.txt", "r")
    data = f.read().replace("\n", "").split(" ")
    moveCube(int(data[0]))
    moveCone(int(data[1]))
