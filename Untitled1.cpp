#include <bits/stdc++.h>

using namespace std;

struct node
{
    int sl;
    int price;
    int total;
    string name;
    node *next;
};

// tao node
node *CreateNode()
{
    node *tmp;
    tmp = new node;
    tmp->next = NULL;
    cout << "Nhap ten: ";
    fflush(stdin);
    getline(cin, tmp->name);
    cout << "Nhap so luong: ";
    cin >> tmp->sl;
    cout << "Nhap gia tien: ";
    cin >> tmp->price;
    return tmp;
    cout << "----------------------------" << endl;
}

// chen node vao vi tri cuoi cung
void insertTail(node *&head)
{
    node *tmp = CreateNode();
    if (head == NULL)
    {
        head = tmp;
        return;
    }
    node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = tmp;
}

// chen node sap xep theo ten
void insertSort(node *&head)
{
    node *tmp = CreateNode();
    node *p = head, *before;
    while (p != NULL && tmp->name > p->name)
    {
        before = p;
        p = p->next;
    }
    if (p == head)
    {
        tmp->next = p;
        head = tmp;
        return;
    }
    before->next = tmp;
    tmp->next = p;
}
// chen node tai vi tri pos
void insertAt(node *&head, int pos)
{
    int idx = 1; // danh sach bat dau tai vi tri 1
    node *p = head, *before;
    while (p != NULL && idx != pos)
    {
        before = p;
        p = p->next;
        idx++;
    }
    if (p == NULL)
    {
        cout << "Vi tri nam ngoai danh sach" << endl;
        return;
    }
    node *tmp = CreateNode();
    if (p == head)
    {
        tmp->next = p;
        head = tmp;
    }
    else
    {
        before->next = tmp;
        tmp->next = p;
    }
}

// xoa node o vi tri pos
void eraseAt(node *&head, int pos)
{
    int idx = 1; // danh sach bat dau tai vi tri 1
    node *p = head, *before;
    while (p != NULL && idx != pos)
    {
        before = p;
        p = p->next;
        idx++;
    }
    if (p == NULL)
    {
        cout << "Vi tri nam ngoai danh sach" << endl;
        return;
    }
    if (p == head)
    {
        head = p->next;
    }
    else
    {
        before->next = p->next;
    }
    delete p;
}
// tim kiem node dau tien trong danh sach co chua ten=name
// tra ve con tro den node do
// tra ve NULL neu khong tim thay
node *find(node *head, string name)
{
    int idx = 1; // danh sach bat dau tai vi tri 1
    node *p = head;
    while (p != NULL && p->name != name)
    {
        p = p->next;
        idx++;
    }
    if (p != NULL)
    {
        cout << "Vi tri " << idx << endl;
        cout << "Ten:" << p->name << endl;
        cout << "So Luong: " << p->sl << endl;
        cout << "Gia Tien: " << p->price << endl;
    }
    else
    {
        cout << "Khong tim thay" << endl;
    }
    return p;
}
// tim kiem tat ca node trong danh sach co chua ten=name
void findAll(node *head, string name)
{
    int idx = 1; // danh sach bat dau tai vi tri 1
    node *p = head;
    while (p != NULL)
    {
        if (p->name == name)
        {
            cout << "Vi tri " << idx << endl;
            cout << "Ten:" << p->name << endl;
            cout << "So Luong: " << p->sl << endl;
            cout << "Gia Tien: " << p->price << endl;
        }
        p = p->next;
        idx++;
    }
}
// khoi tao danh sach
void init(node *&head)
{
    if (head != NULL)
    {
        cout << "Danh sach da duoc khoi tao" << endl;
        return;
    }
    cout << "nhap so luong: ";
    int n;
    cin >> n;
    cout << "----------------------------" << endl;
    for (int i = 1; i <= n; i++)
    {
        insertTail(head);
        cout << "----------------------------" << endl;
    }
}
// Hien thi danh sach lien ket
void display(node *head)
{
    if (head == NULL)
    {
        cout << "Danh sach rong" << endl;
        return;
    }
    cout << "--------Danh sach-----------" << endl;
    node *p = head;
    while (p != NULL)
    {
        cout << "Ten:" << p->name << endl;
        cout << "So Luong: " << p->sl << endl;
        cout << "Gia Tien: " << p->price << endl;
        
        cout << "----------------------------" << endl;
        p = p->next;
    }
}
// tim gia tri data max
// tra ve -1 neu danh sach rong
int findMaxPrice(node *head)
{
    node *p = head;
    int Max = -1;
    while (p != NULL)
    {
        Max = max(Max, p->price);
        p = p->next;
    }
    return Max;
}
// tim tong data
int sumPrice(node *head)
{
    node *p = head;
    int sum = 0;
    while (p != NULL)
    {
        sum += p->price;
        p = p->next;
    }
    return sum;
}
int main()
{
    node *head = NULL;
    // init(head);
    // cout << "----" << endl;
    // display(head);
    // cout << "Chieu cao lon nhat: " << findMaxHeight(head) << endl;
    // eraseAll(head, 3);
    // display(head);
    // int choice;
    while (1)
    {
        cout << "\n-----------------Menu------------------\n";
        cout << "\n1. init\n";
        cout << "\n2. display\n";
        cout << "\n3. insertTail\n";
        cout << "\n4. insertSort\n";
        cout << "\n5. eraseAt\n";
        cout << "\n6. insertAt\n";
        cout << "\n7. findMaxPrice\n";
        cout << "\n8. sumPrice\n";
        cout << "\n--------------------------------------\n";
        cout << "\nEnter your choice:\t";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            init(head);
            break;
        case 2:
        {
            display(head);
            system("pause");
            break;
        }
        case 3:
            insertTail(head);
            break;
        case 4:
            insertSort(head);
            break;
        case 5:
        	int pos;
        	cout << "Nhap vi tri: ";
        	cin >> pos;
        	eraseAt(head, pos);
        	break;
        case 6:
        {
            int pos;
            cout << "Nhap vi tri: ";
            cin >> pos;
            insertAt(head, pos);
            break;
        }
        case 7:
            cout << "Gia lon nhat: " << findMaxPrice(head) << endl;
            break;
        case 8:
            cout << "Tong gia: " << sumPrice(head) << endl;
            break;
        default:
            cout << "\nWrong choice!\n";
            break;
        }
    }
    return 0;
}