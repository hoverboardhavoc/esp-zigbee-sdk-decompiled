/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> price.o -> price_cluster_get_tier_labels_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 price_cluster_get_tier_labels_cmd_handler(int param_1,int param_2,undefined4 *param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uStack_48;
  undefined2 uStack_42;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  int iStack_38;
  undefined4 uStack_34;
  uint uStack_30;
  undefined4 *puStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uStack_40 = 0;
  uStack_3c = 0;
  iStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  puStack_2c = (undefined4 *)0x0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_42 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/price.c",0x8d,
                  "price_cluster_get_tier_labels_cmd_handler","packet && rsp");
  }
  else {
    iVar2 = af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_42,&uStack_34);
    if (iVar2 != 4) {
      uVar1 = 0x80;
      goto _L0;
    }
  }
  uVar1 = zcl_packet_to_message(&uStack_40,param_1);
  if (uVar1 == 0) {
    uStack_30 = CONCAT31(uStack_30._1_3_,0xfe);
    iStack_38 = param_1;
    zcl_core_action_schedule(0x4d,&uStack_40);
    uVar1 = uStack_30 & 0xff;
    if (uVar1 == 0xfe) {
      uVar1 = 0x8b;
    }
    else if (uVar1 == 0) {
      *param_3 = uStack_28;
      param_3[1] = uStack_24;
      if (puStack_2c == (undefined4 *)0x0) {
        uVar1 = 0x8b;
      }
      else {
        uStack_48 = *puStack_2c;
        iVar2 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),4,&uStack_48);
        if (iVar2 == 0) {
          uStack_48 = puStack_2c[1];
          iVar2 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),4,&uStack_48);
          if (iVar2 == 0) {
            uStack_48 = puStack_2c[2];
            iVar2 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),4,&uStack_48);
            if (iVar2 == 0) {
              uStack_48 = CONCAT31(uStack_48._1_3_,*(undefined1 *)(puStack_2c + 3));
              iVar2 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_48);
              if (iVar2 == 0) {
                uStack_48 = CONCAT31(uStack_48._1_3_,*(undefined1 *)((int)puStack_2c + 0xd));
                iVar2 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_48);
                if (iVar2 == 0) {
                  uStack_48 = CONCAT31(uStack_48._1_3_,*(undefined1 *)((int)puStack_2c + 0xe));
                  iVar2 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_48);
                  if (iVar2 == 0) {
                    if (*(char *)((int)puStack_2c + 0xe) == '\0') {
                      uVar1 = 0;
                    }
                    else {
                      uVar1 = 0;
                      if (puStack_2c[4] == 0) {
                        uVar1 = 1;
                        goto _L0;
                      }
                    }
                    for (; uVar1 < *(byte *)((int)puStack_2c + 0xe); uVar1 = uVar1 + 1 & 0xff) {
                      uStack_48 = CONCAT31(uStack_48._1_3_,
                                           *(undefined1 *)(puStack_2c[4] + uVar1 * 0xe));
                      iVar2 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_48);
                      if (iVar2 != 0) {
                        uVar1 = 0x89;
                        goto _L0;
                      }
                      iVar2 = puStack_2c[4] + uVar1 * 0xe;
                      iVar2 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),
                                                *(byte *)(iVar2 + 1) + 1,iVar2 + 1);
                      if (iVar2 != 0) {
                        uVar1 = 0x89;
                        goto _L0;
                      }
                    }
                    uVar1 = zcl_packet_setup_response(param_2,param_1,8);
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
        else {
          uVar1 = 0x89;
        }
      }
    }
  }
_L0:
  uVar3 = zcl_packet_setup_default_response(param_2,param_1,uVar1);
  return uVar3;
}

