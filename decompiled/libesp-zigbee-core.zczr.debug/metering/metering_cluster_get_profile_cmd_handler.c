/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> metering.o -> metering_cluster_get_profile_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 metering_cluster_get_profile_cmd_handler(int param_1,int param_2,undefined4 *param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 local_50;
  ushort uStack_4a;
  uint auStack_48 [6];
  uint uStack_30;
  undefined4 *puStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  auStack_48[0] = 0;
  auStack_48[1] = 0;
  auStack_48[2] = 0;
  auStack_48[3] = 0;
  auStack_48[4] = 0;
  auStack_48[5] = 0;
  uStack_30 = 0;
  puStack_2c = (undefined4 *)0x0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_4a = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/metering.c",0x10a,
                  "metering_cluster_get_profile_cmd_handler","packet && rsp");
  }
  else {
    iVar2 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_4a,auStack_48 + 3);
    if (iVar2 == 0) {
      uVar1 = 0x80;
      goto _L0;
    }
  }
  iVar2 = af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_4a,auStack_48 + 4);
  if (iVar2 == 0) {
    uVar1 = 0x80;
  }
  else {
    iVar2 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_4a,auStack_48 + 5);
    if (iVar2 == 0) {
      uVar1 = 0x80;
    }
    else {
      uVar1 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
      if (uVar1 < uStack_4a) {
        uVar1 = 0x80;
      }
      else if ((auStack_48[5] & 0xff) == 0) {
        uVar1 = 0x87;
      }
      else {
        uVar1 = zcl_packet_to_message(auStack_48,param_1);
        if (uVar1 == 0) {
          uStack_30 = CONCAT31(uStack_30._1_3_,0xfe);
          auStack_48[2] = param_1;
          zcl_core_action_schedule(0x43,auStack_48);
          uVar4 = uStack_30 & 0xff;
          if ((uStack_30 & 0xff) == 0xfe) {
            uVar4 = uVar1;
          }
          uVar1 = uVar4;
          if ((auStack_48[0] & 0xff) == 0xfe) {
            uVar1 = 0x8b;
          }
          else if (uVar1 == 0) {
            if (puStack_2c == (undefined4 *)0x0) {
              uVar1 = 1;
            }
            else {
              local_50 = *puStack_2c;
              iVar2 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),4,&local_50);
              if (iVar2 == 0) {
                local_50 = CONCAT31(local_50._1_3_,*(undefined1 *)(puStack_2c + 1));
                iVar2 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&local_50);
                if (iVar2 == 0) {
                  local_50 = CONCAT31(local_50._1_3_,*(undefined1 *)(puStack_2c + 2));
                  iVar2 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&local_50);
                  if (iVar2 == 0) {
                    local_50 = CONCAT31(local_50._1_3_,*(undefined1 *)(puStack_2c + 3));
                    iVar2 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&local_50);
                    if (iVar2 == 0) {
                      uVar1 = (uint)*(byte *)(puStack_2c + 3);
                      if ((uVar1 == 0) || (puStack_2c[4] != 0)) {
                        if ((auStack_48[5] & 0xff) < uVar1) {
                          uVar1 = auStack_48[5] & 0xff;
                        }
                        for (uVar4 = 0; uVar4 < uVar1; uVar4 = uVar4 + 1 & 0xff) {
                          iVar2 = zcl_packet_append_variable_attr_value
                                            (*(undefined4 *)(param_2 + 0x24),0x22,
                                             puStack_2c[4] + uVar4 * 4);
                          if (iVar2 != 0) {
                            uVar1 = 0x89;
                            goto _L0;
                          }
                        }
                        *param_3 = uStack_28;
                        param_3[1] = uStack_24;
                        uVar1 = zcl_packet_setup_response(param_2,param_1,0);
                        if (uVar1 == 0) {
                          return 0;
                        }
                      }
                      else {
                        uVar1 = 1;
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
_L0:
  uVar3 = zcl_packet_setup_default_response(param_2,param_1,uVar1);
  return uVar3;
}

