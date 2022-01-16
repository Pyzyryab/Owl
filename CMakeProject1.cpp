// CMakeProject1.cpp: define el punto de entrada de la aplicación.
//

#include "CMakeProject1.h"

using namespace std;

using namespace System;
using namespace System::Reflection;

public enum class Access { Read, Write, Execute };
public enum class HttpMethod { GET, POST, PUT, DELETE, DEFAULT };
public enum class Http++Cosa{ asdf, asdfsd, asdfds };

// Defining the Job attribute:
[AttributeUsage( AttributeTargets::Class, AllowMultiple=true )]
public ref class Job : Attribute {
public:
   property int Priority {
      void set( int value ) { m_Priority = value; }
      int get() { return m_Priority; }
   }

   // You can overload constructors to specify Job attribute in different ways
   Job() { m_Access = Access::Read; }
   Job( Access a ) { m_Access = a; }
   Access m_Access;

protected:
   int m_Priority;
};
// Defining the Job attribute:
[AttributeUsage(AttributeTargets::Class, AllowMultiple = true)]
public ref class RestController : Attribute {
private:
public:
    // You can overload constructors to specify Job attribute in different ways
    RestController() { httpMethod = HttpMethod::DEFAULT, path = gcnew String(""); };
    RestController(
        HttpMethod a, 
        String^ p
    ) { 
        httpMethod = a; 
        path = gcnew String(p);
    }
    HttpMethod httpMethod;
    String^ path;
};


interface struct IService {
   void Run();
};

   // Using the Job attribute:
   // Here we specify that QueryService is to be read only with a priority of 2.
   // To prevent namespace collisions, all custom attributes implicitly
   // end with "Attribute".

ref struct QueryService : public IService {
   virtual void Run() {}
};

// Because we said AllowMultiple=true, we can add multiple attributes
[RestController(httpMethod = HttpMethod::POST, path = "INERGYWS")]
ref struct StatsGenerator : public IService {
   virtual void Run( ) {}
};

int main() {
   IService ^ pIS;
   QueryService ^ pQS = gcnew QueryService;
   StatsGenerator ^ pSG = gcnew StatsGenerator;

   //  use QueryService
   pIS = safe_cast<IService ^>( pQS );

   // use StatsGenerator
   pIS = safe_cast<IService ^>( pSG );

   // Reflection
   MemberInfo ^ pMI = pIS->GetType();
   auto pObjs = pMI->GetCustomAttributes(false);

   // We can now quickly and easily view custom attributes for an
   // Object through Reflection */
   for( int i = 0; i < pObjs->Length; i++ ) {
      Console::Write("HTTP METHOD = ");
      Console::WriteLine(static_cast<RestController^>(pObjs[i])->httpMethod);
      Console::Write("PATH = ");
      Console::WriteLine(static_cast<RestController^>(pObjs[i])->path);
   }
}