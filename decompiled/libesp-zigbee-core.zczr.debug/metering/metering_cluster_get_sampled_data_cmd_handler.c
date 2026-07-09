/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> metering.o -> metering_cluster_get_sampled_data_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Type propagation algorithm not settling */

uint metering_cluster_get_sampled_data_cmd_handler(int param_1,int param_2,undefined4 *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 local_50;
  ushort uStack_4a;
  uint auStack_48 [5];
  uint uStack_34;
  undefined1 auStack_32 [2];
  uint uStack_30;
  undefined2 *puStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  auStack_48[0] = 0;
  auStack_48[1] = 0;
  auStack_48[2] = 0;
  auStack_48[3] = 0;
  auStack_48[4] = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  puStack_2c = (undefined2 *)0x0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_4a = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/metering.c",0x1ad,
                  "metering_cluster_get_sampled_data_cmd_handler","packet && rsp");
  }
  else {
    iVar3 = af_read_le16(*(undefined4 *)(param_1 + 0x24),&uStack_4a,auStack_48 + 3);
    if (iVar3 == 0) {
      uVar1 = 0x80;
      goto _L0;
    }
  }
  iVar3 = af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_4a,auStack_48 + 4);
  if (iVar3 == 0) {
    uVar1 = 0x80;
  }
  else {
    iVar3 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_4a,&stack0xffffffcc);
    if (iVar3 == 0) {
      uVar1 = 0x80;
    }
    else {
      iVar3 = af_read_le16(*(undefined4 *)(param_1 + 0x24),&uStack_4a,auStack_32);
      if (iVar3 == 0) {
        uVar1 = 0x80;
      }
      else {
        uVar1 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
        if (uVar1 < uStack_4a) {
          uVar1 = 0x80;
        }
        else if (uStack_34 >> 0x10 == 0) {
          uVar1 = 0x87;
        }
        else {
          uVar1 = zcl_packet_to_message(auStack_48,param_1);
          if (uVar1 == 0) {
            uStack_30 = CONCAT31(uStack_30._1_3_,0xfe);
            auStack_48[2] = param_1;
            zcl_core_action_schedule(0x49,auStack_48);
            uVar2 = uStack_30 & 0xff;
            if ((uStack_30 & 0xff) == 0xfe) {
              uVar2 = uVar1;
            }
            uVar1 = uVar2;
            if ((auStack_48[0] & 0xff) == 0xfe) {
              uVar1 = 0x8b;
            }
            else if (uVar1 == 0) {
              if (puStack_2c[6] == 0) {
                uVar1 = 0x8b;
              }
              else if (*(int *)(puStack_2c + 8) == 0) {
                uVar1 = 0x8b;
              }
              else {
                local_50 = CONCAT22(local_50._2_2_,*puStack_2c);
                iVar3 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&local_50);
                if (iVar3 == 0) {
                  local_50 = *(undefined4 *)(puStack_2c + 2);
                  iVar3 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),4,&local_50);
                  if (iVar3 == 0) {
                    local_50 = CONCAT31(local_50._1_3_,*(undefined1 *)(puStack_2c + 4));
                    iVar3 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&local_50);
                    if (iVar3 == 0) {
                      local_50 = CONCAT22(local_50._2_2_,puStack_2c[5]);
                      iVar3 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&local_50);
                      if (iVar3 == 0) {
                        local_50 = CONCAT22(local_50._2_2_,puStack_2c[6]);
                        iVar3 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&local_50);
                        if (iVar3 == 0) {
                          uVar1 = uStack_34 >> 0x10;
                          if ((uint)(ushort)puStack_2c[6] < uStack_34 >> 0x10) {
                            uVar1 = (uint)(ushort)puStack_2c[6];
                          }
                          for (uVar2 = 0; uVar2 < uVar1; uVar2 = uVar2 + 1 & 0xffff) {
                            iVar3 = zcl_packet_append_variable_attr_value
                                              (*(undefined4 *)(param_2 + 0x24),0x22,
                                               *(int *)(puStack_2c + 8) + uVar2 * 4);
                            if (iVar3 != 0) {
                              uVar1 = 0x89;
                              goto _L0;
                            }
                          }
                          *param_3 = uStack_28;
                          param_3[1] = uStack_24;
                          uVar1 = zcl_packet_setup_response(param_2,param_1,7);
                          if (uVar1 == 0) {
                            return 0;
                          }
                        }
                        else {
                          uVar1 = 0x89;
                        }
                      }
                      else {
                        uVar1 = 0x89;
                      }
                    }
                    else {
                      uVar1 = 0x89;
                    }
                  }
                  else {
                    uVar1 = 0x89;
                  }
                }
                else {
                  uVar1 = 0x89;
                }
              }
            }
          }
        }
      }
    }
  }
_L0:
  uVar1 = zcl_packet_setup_default_response(param_2,param_1,uVar1);
  return uVar1;
}

