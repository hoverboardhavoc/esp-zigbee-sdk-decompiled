/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> metering.o -> metering_cluster_get_snapshot_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 metering_cluster_get_snapshot_cmd_handler(int param_1,int param_2,undefined4 *param_3)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uStack_54;
  ushort uStack_4e;
  uint uStack_4c;
  undefined4 uStack_48;
  int iStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  uint uStack_30;
  undefined4 *puStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uStack_4c = 0;
  uStack_48 = 0;
  iStack_44 = 0;
  uStack_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  puStack_2c = (undefined4 *)0x0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_4e = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/metering.c",0x156,
                  "metering_cluster_get_snapshot_cmd_handler","packet && rsp");
  }
  else {
    iVar4 = af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_4e,&uStack_40);
    if (iVar4 == 0) {
      uVar3 = 0x80;
      goto _L0;
    }
  }
  iVar4 = af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_4e,&uStack_3c);
  if (iVar4 == 0) {
    uVar3 = 0x80;
  }
  else {
    iVar4 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_4e,&uStack_38);
    if (iVar4 == 0) {
      uVar3 = 0x80;
    }
    else {
      iVar4 = af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_4e,&uStack_34);
      if (iVar4 == 0) {
        uVar3 = 0x80;
      }
      else {
        uVar3 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
        if (uVar3 < uStack_4e) {
          uVar3 = 0x80;
        }
        else {
          uVar3 = zcl_packet_to_message(&uStack_4c,param_1);
          if (uVar3 == 0) {
            uStack_30 = CONCAT31(uStack_30._1_3_,0xfe);
            iStack_44 = param_1;
            zcl_core_action_schedule(0x47,&uStack_4c);
            uVar2 = uStack_30 & 0xff;
            if ((uStack_30 & 0xff) == 0xfe) {
              uVar2 = uVar3;
            }
            uVar3 = uVar2;
            if ((uStack_4c & 0xff) == 0xfe) {
              uVar3 = 0x8b;
            }
            else if (uVar3 == 0) {
              uStack_54 = *puStack_2c;
              iVar4 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),4,&uStack_54);
              if (iVar4 == 0) {
                uStack_54 = puStack_2c[1];
                iVar4 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),4,&uStack_54);
                if (iVar4 == 0) {
                  uStack_54 = CONCAT31(uStack_54._1_3_,*(undefined1 *)(puStack_2c + 2));
                  iVar4 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_54);
                  if (iVar4 == 0) {
                    uStack_54 = CONCAT31(uStack_54._1_3_,*(undefined1 *)((int)puStack_2c + 9));
                    iVar4 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_54);
                    if (iVar4 == 0) {
                      uStack_54 = CONCAT31(uStack_54._1_3_,*(undefined1 *)((int)puStack_2c + 10));
                      iVar4 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_54);
                      if (iVar4 == 0) {
                        uStack_54 = puStack_2c[3];
                        iVar4 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),4,&uStack_54);
                        if (iVar4 == 0) {
                          uStack_54 = CONCAT31(uStack_54._1_3_,*(undefined1 *)(puStack_2c + 4));
                          iVar4 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_54);
                          if (iVar4 == 0) {
                            bVar1 = *(byte *)(puStack_2c + 4);
                            if (bVar1 == 4) {
                              uVar3 = append_tou_info_no_billing_set_to_payload
                                                (*(undefined4 *)(param_2 + 0x24),puStack_2c + 6);
                            }
                            else if (bVar1 < 5) {
                              if (bVar1 == 2) {
                                uVar3 = append_block_info_set_to_payload
                                                  (*(undefined4 *)(param_2 + 0x24),puStack_2c + 6);
                              }
                              else if (bVar1 < 3) {
                                if (bVar1 == 0) {
                                  uVar3 = append_tou_info_set_to_payload
                                                    (*(undefined4 *)(param_2 + 0x24),puStack_2c + 6)
                                  ;
                                }
                                else {
                                  if (bVar1 != 1) {
                                    uVar3 = 1;
                                    goto _L0;
                                  }
                                  uVar3 = append_tou_info_set_to_payload
                                                    (*(undefined4 *)(param_2 + 0x24),puStack_2c + 6)
                                  ;
                                }
                              }
                              else {
                                if (bVar1 != 3) {
                                  uVar3 = 1;
                                  goto _L0;
                                }
                                uVar3 = append_block_info_set_to_payload
                                                  (*(undefined4 *)(param_2 + 0x24),puStack_2c + 6);
                              }
                            }
                            else if (bVar1 == 6) {
                              uVar3 = append_block_info_no_billing_set_to_payload
                                                (*(undefined4 *)(param_2 + 0x24),puStack_2c + 6);
                            }
                            else if (bVar1 == 7) {
                              uVar3 = append_block_info_no_billing_set_to_payload
                                                (*(undefined4 *)(param_2 + 0x24),puStack_2c + 6);
                            }
                            else {
                              if (bVar1 != 5) {
                                uVar3 = 1;
                                goto _L0;
                              }
                              uVar3 = append_tou_info_no_billing_set_to_payload
                                                (*(undefined4 *)(param_2 + 0x24),puStack_2c + 6);
                            }
                            if (uVar3 == 0) {
                              *param_3 = uStack_28;
                              param_3[1] = uStack_24;
                              uVar3 = zcl_packet_setup_response(param_2,param_1,6);
                              if (uVar3 == 0) {
                                return 0;
                              }
                            }
                          }
                          else {
                            uVar3 = 0x89;
                          }
                        }
                        else {
                          uVar3 = 0x89;
                        }
                      }
                      else {
                        uVar3 = 0x89;
                      }
                    }
                    else {
                      uVar3 = 0x89;
                    }
                  }
                  else {
                    uVar3 = 0x89;
                  }
                }
                else {
                  uVar3 = 0x89;
                }
              }
              else {
                uVar3 = 0x89;
              }
            }
          }
        }
      }
    }
  }
_L0:
  uVar5 = zcl_packet_setup_default_response(param_2,param_1,uVar3);
  return uVar5;
}

