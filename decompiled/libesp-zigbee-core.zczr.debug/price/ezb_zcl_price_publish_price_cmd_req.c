/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> price.o -> ezb_zcl_price_publish_price_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Type propagation algorithm not settling */

int ezb_zcl_price_publish_price_cmd_req(int param_1)

{
  int iVar1;
  uint auStack_3c [12];
  
  auStack_3c[1] = 0;
  auStack_3c[2] = 0;
  auStack_3c[3] = 0;
  auStack_3c[4] = 0;
  auStack_3c[5] = 0;
  auStack_3c[6] = 0;
  auStack_3c[7] = 0;
  auStack_3c[8] = 0;
  auStack_3c[9] = 0;
  auStack_3c[10] = 0;
  if (param_1 == 0) {
    iVar1 = -1;
  }
  else {
    iVar1 = zcl_packet_init(auStack_3c + 1,0);
    if ((iVar1 == 0) &&
       (iVar1 = zcl_cmd_to_packet(auStack_3c + 1,0,1,*(undefined1 *)(param_1 + 0xc),0,0,0x700),
       iVar1 == 0)) {
      auStack_3c[0] = *(uint *)(param_1 + 0x18);
      iVar1 = zmsg_append_bytes(auStack_3c[10],4,auStack_3c);
      if (iVar1 == 0) {
        if (*(byte *)(param_1 + 0x1c) < 0xd) {
          iVar1 = zmsg_append_bytes(auStack_3c[10],*(byte *)(param_1 + 0x1c) + 1,param_1 + 0x1c);
          if (iVar1 == 0) {
            auStack_3c[0] = (uint)*(byte *)(param_1 + 0x2c) << 0x18 | *(uint *)(param_1 + 0x28) >> 8
            ;
            iVar1 = zmsg_append_bytes(auStack_3c[10],4,auStack_3c);
            if (iVar1 == 0) {
              auStack_3c[0] =
                   (uint)*(byte *)(param_1 + 0x30) << 0x18 | *(uint *)(param_1 + 0x2c) >> 8;
              iVar1 = zmsg_append_bytes(auStack_3c[10],4,auStack_3c);
              if (iVar1 == 0) {
                auStack_3c[0] = CONCAT31(auStack_3c[0]._1_3_,*(undefined1 *)(param_1 + 0x31));
                iVar1 = zmsg_append_bytes(auStack_3c[10],1,auStack_3c);
                if (iVar1 == 0) {
                  auStack_3c[0] = CONCAT22(auStack_3c[0]._2_2_,*(undefined2 *)(param_1 + 0x32));
                  iVar1 = zmsg_append_bytes(auStack_3c[10],2,auStack_3c);
                  if (iVar1 == 0) {
                    auStack_3c[0] =
                         CONCAT31(auStack_3c[0]._1_3_,
                                  (byte)(*(uint *)(param_1 + 0x34) >> 4) & 0xf |
                                  (byte)((*(uint *)(param_1 + 0x34) & 0xf) << 4));
                    iVar1 = zmsg_append_bytes(auStack_3c[10],1,auStack_3c);
                    if (iVar1 == 0) {
                      auStack_3c[0] =
                           CONCAT31(auStack_3c[0]._1_3_,
                                    (byte)((*(uint *)(param_1 + 0x34) >> 8 & 0xf) << 4) |
                                    (byte)(*(uint *)(param_1 + 0x34) >> 0xc) & 0xf);
                      iVar1 = zmsg_append_bytes(auStack_3c[10],1,auStack_3c);
                      if (iVar1 == 0) {
                        auStack_3c[0] = *(uint *)(param_1 + 0x36);
                        iVar1 = zmsg_append_bytes(auStack_3c[10],4,auStack_3c);
                        if (iVar1 == 0) {
                          auStack_3c[0] =
                               CONCAT22(auStack_3c[0]._2_2_,*(undefined2 *)(param_1 + 0x3a));
                          iVar1 = zmsg_append_bytes(auStack_3c[10],2,auStack_3c);
                          if (iVar1 == 0) {
                            auStack_3c[0] = *(uint *)(param_1 + 0x3c);
                            iVar1 = zmsg_append_bytes(auStack_3c[10],4,auStack_3c);
                            if (iVar1 == 0) {
                              auStack_3c[0] =
                                   CONCAT31(auStack_3c[0]._1_3_,*(undefined1 *)(param_1 + 0x40));
                              iVar1 = zmsg_append_bytes(auStack_3c[10],1,auStack_3c);
                              if (iVar1 == 0) {
                                auStack_3c[0] =
                                     (uint)*(byte *)(param_1 + 0x44) << 0x18 |
                                     *(uint *)(param_1 + 0x40) >> 8;
                                iVar1 = zmsg_append_bytes(auStack_3c[10],4,auStack_3c);
                                if (iVar1 == 0) {
                                  auStack_3c[0] =
                                       CONCAT31(auStack_3c[0]._1_3_,*(undefined1 *)(param_1 + 0x45))
                                  ;
                                  iVar1 = zmsg_append_bytes(auStack_3c[10],1,auStack_3c);
                                  if (iVar1 == 0) {
                                    auStack_3c[0] = *(uint *)(param_1 + 0x46);
                                    iVar1 = zmsg_append_bytes(auStack_3c[10],4,auStack_3c);
                                    if (iVar1 == 0) {
                                      auStack_3c[0] =
                                           CONCAT31(auStack_3c[0]._1_3_,
                                                    *(undefined1 *)(param_1 + 0x4a));
                                      iVar1 = zmsg_append_bytes(auStack_3c[10],1,auStack_3c);
                                      if (iVar1 == 0) {
                                        auStack_3c[0] =
                                             CONCAT31(auStack_3c[0]._1_3_,
                                                      *(undefined1 *)(param_1 + 0x4b));
                                        iVar1 = zmsg_append_bytes(auStack_3c[10],1,auStack_3c);
                                        if (iVar1 == 0) {
                                          auStack_3c[0] =
                                               CONCAT31(auStack_3c[0]._1_3_,
                                                        *(undefined1 *)(param_1 + 0x4c));
                                          iVar1 = zmsg_append_bytes(auStack_3c[10],1,auStack_3c);
                                          if (iVar1 == 0) {
                                            auStack_3c[0] =
                                                 CONCAT31(auStack_3c[0]._1_3_,
                                                          *(undefined1 *)(param_1 + 0x4d));
                                            iVar1 = zmsg_append_bytes(auStack_3c[10],1,auStack_3c);
                                            if (iVar1 == 0) {
                                              auStack_3c[0] =
                                                   CONCAT31(auStack_3c[0]._1_3_,
                                                            *(undefined1 *)(param_1 + 0x4e));
                                              iVar1 = zmsg_append_bytes(auStack_3c[10],1,auStack_3c)
                                              ;
                                              if (iVar1 == 0) {
                                                auStack_3c[0] =
                                                     CONCAT31(auStack_3c[0]._1_3_,
                                                              *(undefined1 *)(param_1 + 0x4f));
                                                iVar1 = zmsg_append_bytes(auStack_3c[10],1,
                                                                          auStack_3c);
                                                if (iVar1 == 0) {
                                                  auStack_3c[0] =
                                                       CONCAT31(auStack_3c[0]._1_3_,
                                                                *(undefined1 *)(param_1 + 0x50));
                                                  iVar1 = zmsg_append_bytes(auStack_3c[10],1,
                                                                            auStack_3c);
                                                  if (iVar1 == 0) {
                                                    auStack_3c[0] =
                                                         CONCAT31(auStack_3c[0]._1_3_,
                                                                  *(undefined1 *)(param_1 + 0x51));
                                                    iVar1 = zmsg_append_bytes(auStack_3c[10],1,
                                                                              auStack_3c);
                                                    if (iVar1 == 0) {
                                                      auStack_3c[0] =
                                                           CONCAT31(auStack_3c[0]._1_3_,
                                                                    *(undefined1 *)(param_1 + 0x52))
                                                      ;
                                                      iVar1 = zmsg_append_bytes(auStack_3c[10],1,
                                                                                auStack_3c);
                                                      if (iVar1 == 0) {
                                                        zcl_packet_send(auStack_3c + 1,
                                                                        param_1 + 0x10);
                                                        iVar1 = zcl_status_to_err();
                                                        if (iVar1 == 0) {
                                                          return 0;
                                                        }
                                                      }
                                                      else {
                                                        iVar1 = 1;
                                                      }
                                                    }
                                                    else {
                                                      iVar1 = 1;
                                                    }
                                                  }
                                                  else {
                                                    iVar1 = 1;
                                                  }
                                                }
                                                else {
                                                  iVar1 = 1;
                                                }
                                              }
                                              else {
                                                iVar1 = 1;
                                              }
                                            }
                                            else {
                                              iVar1 = 1;
                                            }
                                          }
                                          else {
                                            iVar1 = 1;
                                          }
                                        }
                                        else {
                                          iVar1 = 1;
                                        }
                                      }
                                      else {
                                        iVar1 = 1;
                                      }
                                    }
                                    else {
                                      iVar1 = 1;
                                    }
                                  }
                                  else {
                                    iVar1 = 1;
                                  }
                                }
                                else {
                                  iVar1 = 1;
                                }
                              }
                              else {
                                iVar1 = 1;
                              }
                            }
                            else {
                              iVar1 = 1;
                            }
                          }
                          else {
                            iVar1 = 1;
                          }
                        }
                        else {
                          iVar1 = 1;
                        }
                      }
                      else {
                        iVar1 = 1;
                      }
                    }
                    else {
                      iVar1 = 1;
                    }
                  }
                  else {
                    iVar1 = 1;
                  }
                }
                else {
                  iVar1 = 1;
                }
              }
              else {
                iVar1 = 1;
              }
            }
            else {
              iVar1 = 1;
            }
          }
          else {
            iVar1 = 1;
          }
        }
        else {
          iVar1 = 2;
        }
      }
      else {
        iVar1 = 1;
      }
    }
  }
  zcl_packet_free(auStack_3c + 1);
  return iVar1;
}

