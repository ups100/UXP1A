///////////////////////////////////////////////////////////
//  ClientCommunication.h
//  Implementation of the Class ClientCommunication
//  Created on:      24-kwi-2013 11:07:18
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_E5ED41B2_C079_426d_84A5_B5150BB1C442__INCLUDED_)
#define EA_E5ED41B2_C079_426d_84A5_B5150BB1C442__INCLUDED_

class ClientCommunication
{

public:
    ClientCommunication();
    virtual ~ClientCommunication();

    void sendRecord(QString pattern, QVariant data);
    void sendTimeoutInfo();

private:
    QString m_clientPath;

};
#endif // !defined(EA_E5ED41B2_C079_426d_84A5_B5150BB1C442__INCLUDED_)
