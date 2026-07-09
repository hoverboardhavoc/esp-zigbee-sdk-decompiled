/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> metering.o -> metering_cluster_publish_snapshot_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void metering_cluster_publish_snapshot_cmd_handler(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined2 uStack_7a;
  undefined1 auStack_78 [8];
  int iStack_70;
  undefined1 auStack_68 [4];
  undefined1 auStack_64 [4];
  undefined1 uStack_60;
  undefined1 uStack_5f;
  undefined1 auStack_5e [2];
  undefined1 auStack_5c [4];
  byte abStack_58 [8];
  undefined1 auStack_50 [12];
  int iStack_44;
  int iStack_3c;
  int iStack_34;
  int iStack_2c;
  byte bStack_28;
  
  memset(auStack_78,0,0x58);
  uStack_7a = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/metering.c",0x209,
                  "metering_cluster_publish_snapshot_cmd_handler","packet && rsp");
  }
  else {
    iVar1 = af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_7a,auStack_68);
    if (iVar1 != 4) {
      iVar1 = 0;
      uVar2 = 0x80;
      goto _L0;
    }
  }
  iVar1 = af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_7a,auStack_64);
  if (iVar1 == 4) {
    iVar1 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_7a,&uStack_60);
    if (iVar1 == 1) {
      iVar1 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_7a,&uStack_5f);
      if (iVar1 == 1) {
        iVar1 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_7a,auStack_5e);
        if (iVar1 == 1) {
          iVar1 = af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_7a,auStack_5c);
          if (iVar1 == 4) {
            iVar1 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_7a,abStack_58);
            if (iVar1 == 1) {
              if (abStack_58[0] == 4) {
                uVar2 = parse_tou_info_no_billing_set_from_payload
                                  (*(undefined4 *)(param_1 + 0x24),&uStack_7a,auStack_50);
                if (uVar2 != 0) {
                  iVar1 = 0;
                  goto _L0;
                }
                iVar1 = 0;
                iVar3 = iStack_44;
              }
              else if (abStack_58[0] < 5) {
                if (abStack_58[0] == 2) {
                  uVar2 = parse_block_info_set_from_payload
                                    (*(undefined4 *)(param_1 + 0x24),&uStack_7a,auStack_50);
                  iVar1 = iStack_2c;
                  iVar3 = iStack_34;
                  if (uVar2 != 0) {
                    iVar1 = 0;
                    goto _L0;
                  }
                }
                else if (abStack_58[0] < 3) {
                  if (abStack_58[0] == 0) {
                    uVar2 = parse_tou_info_set_from_payload
                                      (*(undefined4 *)(param_1 + 0x24),&uStack_7a,auStack_50);
                    if (uVar2 != 0) {
                      iVar1 = 0;
                      goto _L0;
                    }
                    iVar1 = 0;
                    iVar3 = iStack_34;
                  }
                  else {
                    if (abStack_58[0] != 1) {
                      iVar1 = 0;
                      uVar2 = 0x87;
                      goto _L0;
                    }
                    uVar2 = parse_tou_info_set_from_payload
                                      (*(undefined4 *)(param_1 + 0x24),&uStack_7a,auStack_50);
                    if (uVar2 != 0) {
                      iVar1 = 0;
                      goto _L0;
                    }
                    iVar1 = 0;
                    iVar3 = iStack_34;
                  }
                }
                else {
                  if (abStack_58[0] != 3) {
                    iVar1 = 0;
                    uVar2 = 0x87;
                    goto _L0;
                  }
                  uVar2 = parse_block_info_set_from_payload
                                    (*(undefined4 *)(param_1 + 0x24),&uStack_7a,auStack_50);
                  iVar1 = iStack_2c;
                  iVar3 = iStack_34;
                  if (uVar2 != 0) {
                    iVar1 = 0;
                    goto _L0;
                  }
                }
              }
              else if (abStack_58[0] == 6) {
                uVar2 = parse_block_info_no_billing_set_from_payload
                                  (*(undefined4 *)(param_1 + 0x24),&uStack_7a,auStack_50);
                iVar1 = iStack_3c;
                iVar3 = iStack_44;
                if (uVar2 != 0) {
                  iVar1 = 0;
                  goto _L0;
                }
              }
              else if (abStack_58[0] == 7) {
                uVar2 = parse_block_info_no_billing_set_from_payload
                                  (*(undefined4 *)(param_1 + 0x24),&uStack_7a,auStack_50);
                iVar1 = iStack_3c;
                iVar3 = iStack_44;
                if (uVar2 != 0) {
                  iVar1 = 0;
                  goto _L0;
                }
              }
              else {
                if (abStack_58[0] != 5) {
                  iVar1 = 0;
                  uVar2 = 0x87;
                  goto _L0;
                }
                uVar2 = parse_tou_info_no_billing_set_from_payload
                                  (*(undefined4 *)(param_1 + 0x24),&uStack_7a,auStack_50);
                if (uVar2 != 0) {
                  iVar1 = 0;
                  goto _L0;
                }
                iVar1 = 0;
                iVar3 = iStack_44;
              }
              uVar2 = zcl_packet_to_message(auStack_78,param_1);
              if (uVar2 == 0) {
                bStack_28 = 0xfe;
                iStack_70 = param_1;
                zcl_core_action_schedule(0x48,auStack_78);
                if (bStack_28 != 0xfe) {
                  uVar2 = (uint)bStack_28;
                }
              }
              if (iVar3 != 0) {
                mm_free(iVar3);
              }
            }
            else {
              iVar1 = 0;
              uVar2 = 0x80;
            }
          }
          else {
            iVar1 = 0;
            uVar2 = 0x80;
          }
        }
        else {
          iVar1 = 0;
          uVar2 = 0x80;
        }
      }
      else {
        iVar1 = 0;
        uVar2 = 0x80;
      }
    }
    else {
      iVar1 = 0;
      uVar2 = 0x80;
    }
  }
  else {
    iVar1 = 0;
    uVar2 = 0x80;
  }
_L0:
  if (iVar1 != 0) {
    mm_free(iVar1);
  }
  zcl_packet_setup_default_response(param_2,param_1,uVar2);
  return;
}

