import pybullet as p
import pybullet_data
import time


def helloworld():
    physicsClient = p.connect(p.GUI)
    p.setAdditionalSearchPath(pybullet_data.getDataPath())  # optionally
    p.setGravity(0, 0, -10)
    planeId = p.loadURDF("plane.urdf")
    cubeStartPos = [0, 0, 1]
    cubeStartOrientation = p.getQuaternionFromEuler([0, 0, 0])
    boxId = p.loadURDF("r2d2.urdf", cubeStartPos, cubeStartOrientation)

    for i in range(1000):
        p.stepSimulation()
        time.sleep(1.0 / 240.0)

    p.disconnect()
