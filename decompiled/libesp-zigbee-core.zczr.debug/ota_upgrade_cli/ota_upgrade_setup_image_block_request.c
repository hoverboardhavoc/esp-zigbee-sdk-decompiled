/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_setup_image_block_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ota_upgrade_setup_image_block_request(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 uVar3;
  int unaff_s2;
  char cVar4;
  undefined4 uVar5;
  uint auStack_24 [3];
  
  if (*(int *)(param_2 + 0x24) == 0) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x02';
  }
  if (((param_1 == 0) || (param_3 == 0)) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_cli.c",
                  0x255,"ota_upgrade_setup_image_block_request",
                  "sent_packet && recv_packet && context");
  }
  else {
    unaff_s2 = zcl_packet_setup_response_with_extension(param_1,3,1,0);
    if (unaff_s2 != 0) {
      return unaff_s2;
    }
  }
  auStack_24[0] = CONCAT31(auStack_24[0]._1_3_,cVar4) | 1;
  iVar1 = zmsg_append_bytes(*(undefined4 *)(param_1 + 0x24),1,auStack_24);
  if (iVar1 == 0) {
    auStack_24[0]._0_2_ = **(undefined2 **)(param_2 + 0x1c);
    iVar1 = zmsg_append_bytes(*(undefined4 *)(param_1 + 0x24),2,auStack_24);
    if (iVar1 == 0) {
      auStack_24[0] = CONCAT22(auStack_24[0]._2_2_,**(undefined2 **)(param_2 + 0x20));
      iVar1 = zmsg_append_bytes(*(undefined4 *)(param_1 + 0x24),2,auStack_24);
      if (iVar1 == 0) {
        auStack_24[0] = *(uint *)(param_2 + 0x2c);
        iVar1 = zmsg_append_bytes(*(undefined4 *)(param_1 + 0x24),4,auStack_24);
        if (iVar1 == 0) {
          auStack_24[0] = **(uint **)(param_2 + 4);
          iVar1 = zmsg_append_bytes(*(undefined4 *)(param_1 + 0x24),4,auStack_24);
          if (iVar1 == 0) {
            auStack_24[0] = CONCAT31(auStack_24[0]._1_3_,*(undefined1 *)(param_2 + 0x30));
            iVar1 = zmsg_append_bytes(*(undefined4 *)(param_1 + 0x24),1,auStack_24);
            if (iVar1 == 0) {
              uVar5 = *(undefined4 *)(param_1 + 0x24);
              uVar2 = nwk_get_extended_address();
              iVar1 = zmsg_append_bytes(uVar5,8,uVar2);
              if (iVar1 == 0) {
                if (cVar4 == '\0') {
                  unaff_s2 = 0;
                }
                else {
                  if (*(undefined2 **)(param_2 + 0x24) == (undefined2 *)0x0) {
                    uVar3 = 0;
                  }
                  else {
                    uVar3 = **(undefined2 **)(param_2 + 0x24);
                  }
                  auStack_24[0] = CONCAT22(auStack_24[0]._2_2_,uVar3);
                  iVar1 = zmsg_append_bytes(*(undefined4 *)(param_1 + 0x24),2,auStack_24);
                  if (iVar1 != 0) {
                    unaff_s2 = 0x89;
                  }
                }
              }
              else {
                unaff_s2 = 0x89;
              }
            }
            else {
              unaff_s2 = 0x89;
            }
          }
          else {
            unaff_s2 = 0x89;
          }
        }
        else {
          unaff_s2 = 0x89;
        }
      }
      else {
        unaff_s2 = 0x89;
      }
    }
    else {
      unaff_s2 = 0x89;
    }
  }
  else {
    unaff_s2 = 0x89;
  }
  return unaff_s2;
}

