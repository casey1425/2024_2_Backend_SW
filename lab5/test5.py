import person_pb2
import sys

def main(argv):
    with open('mybinary', mode='rb') as f:
        s = f.read()
        p = person_pb2.Person()
        p.ParseFromString(s)
        print('name:', p.name)
        print('id:', p.id)
        print('Phone1:', p.phone[0].type, p.phones[0].number)
        print(p)

if __name__ == '__main__':
    main(sys.argv)