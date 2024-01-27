#! /usr/bin/python
from proto_msg.src import hansolo_pb2

if __name__=="__main__":
    han=hansolo_pb2.Person()
    han.name="hansolo"
    han.id=1
    han.age=23
    han.my_vector.append(111)
    han.my_vector.append(222)


    print(han.SerializeToString())
