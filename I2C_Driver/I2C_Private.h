/*
 *  I2C_Driver
 *  I2C_Private.h
 *  Created on: Jun 20, 2023
 *  Author: Heba Atef Ahmed
 */

#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_

#define START_ACK                            0X08            // start has been sent
#define REP_START_ACK                        0X10            // Repeated start
#define SLAVE_ADD_AND_WR_ACK                 0X18            // Master transmit (slave address + write request) ACK
#define SLAVE_ADD_AND_RD_ACK                 0X40            // Master transmit (slave address + Read request) ACK
#define MSTR_WR_BYTE_ACK                     0X28            // Master transmit data ACK
#define MSTR_RD_BYTE_WITH_ACK                0X50            // Master Received data with ACK
#define MSTR_RD_BYTE_WITH_NACK               0X58            // Master Received data with not ACK
#define SLAVE_ADD_RCVD_RD_REQ                0XA8            // Means that slave address is received with read request
#define SLAVE_ADD_RCVD_WR_REQ                0X60            // Means that slave address is received with write request
#define SLAVE_DATA_RECEIVED                  0X80            // Means that a byte is received
#define SLAVE_BYTE_TRANSMITTED               0XB8            // Means that the written byte is transmitted


#endif /* I2C_PRIVATE_H_ */
