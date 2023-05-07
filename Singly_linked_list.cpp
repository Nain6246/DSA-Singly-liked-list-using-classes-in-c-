#include <iostream>
using namespace std;
struct student
{
   string name;
   int roll_no;
   float cgpa;

   student *next;
};
class dsa_class
{
public:
   student *head;
   student *tail;

   int count;
   dsa_class()
   {
      head = NULL;
      tail = NULL;
      count = 0;
   }
   ~dsa_class()
   {
      student *temp = head;
      while (temp->next == tail)
      {
         temp = temp->next;
         delete temp;
      }
      delete head;
      delete tail;
      head = NULL;
      tail = NULL;
   }
   student *input_student()
   {
      student *new_node = new student;
      cout << "Enter name :";
      cin >> new_node->name;
      cout << "Enter roll no  :";
      cin >> new_node->roll_no;
      cout << "Enter cgpa :";
      cin >> new_node->cgpa;
      return new_node;
   }
   void insert_at_start()
   {
      student *new_node = input_student();
      if (head == NULL)
      {
         tail = new_node;
      }
      new_node->next = head;
      head = new_node;
      new_node = NULL;
      count++;
   }
   void dsiplay_student_inserted()
   {
      student *temp = head;
      cout << "\tName \tRoll_no\tCgpa " << endl;
      while (temp != NULL)
      {
         cout << "\t" << temp->name << "\t" << temp->roll_no << "\t" << temp->cgpa << endl;
         temp = temp->next;
      }
   }
   void insert_at_end()
   {
      student *newnode = input_student();
      tail->next = newnode;
      tail = newnode;
      newnode->next = NULL;
      newnode = NULL;
      count++;
   }

   void insert_at_location()
   {
      int loc;
      cout << "Total node :" << count << endl;
      do
      {
         cout << "enter location :";
         cin >> loc;
      } while (loc > 0 && count < loc);

      student *newnode = input_student();
      int i = 1;
      student *temp = head;
      while (i < loc)
      {
         temp = temp->next;
         i++;
      }
      newnode->next = temp->next;
      temp->next = newnode;
      count++;

      if (tail == temp)
      {
         tail = newnode;
      }
      newnode = NULL;
      temp = NULL;
   }
   void deletion_start()
   {
      if (head != NULL)
      {
         student *temp = head;
         head = head->next;
         delete temp;
         if (head == NULL)
         {
            tail = NULL;
         }
         count--;
         temp = NULL;
      }
      else
      {
         cout << "Linked list is empty :" << endl;
      }
   }
   int find_student_location_by_roll_number(int roll)
   {
      int loc = -1;
      if (head != NULL)
      {
         student *temp = head;
         int i = 1;
         while (temp->roll_no != roll && temp->next != NULL)
         {
            temp = temp->next;
            i++;
         }
         if (temp->roll_no == roll)
         {
            loc = i;
         }
         temp = NULL;
      }
      return loc;
   };

   void delete_at_location()
   {
      int loc, rollNo;

      cout << "Enter Roll Number to delete a student: ";
      cin >> rollNo;

      loc = find_student_location_by_roll_number(rollNo);

      if (loc != -1)
      {
         if (head->next == NULL)
         {
            delete head;
            head = tail = NULL;
         }
         else if (loc == 1)
         {
            student *temp = head;
            head = head->next;
            delete temp;
            temp = NULL;
         }
         else
         {
            int i = 1;
            student *temp = head;

            while (i < loc - 1)
            {
               temp = temp->next;
               i++;
            }

            student *ptr = temp->next;
            temp->next = temp->next->next;
            if (tail == ptr)
               tail = temp;
            delete ptr;

            ptr = NULL;
            temp = NULL;
         }
         count--;
      }
      else
      {
         cout << "Student does not exist against roll number " << rollNo << endl;
      }
   }

   void delete_at_end()
   {
      student *temp = head;
      student *pre;
      while (temp->next != NULL)
      {
         pre = temp;
         temp = temp->next;
      }
      pre->next = NULL;
      delete temp;
   }
};
int main()
{
   dsa_class obj;
   for (int i = 0; i < 2; i++)
   {
      obj.insert_at_start();
   }
   obj.delete_at_location();
   obj.dsiplay_student_inserted();
}
