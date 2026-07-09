/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_commands.o -> aps_cmd_handle_verify_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_cmd_handle_verify_key(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  ushort uVar4;
  undefined1 uVar5;
  undefined1 auStack_60 [16];
  undefined4 uStack_50;
  undefined4 uStack_4c;
  uint auStack_48 [4];
  undefined1 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined2 uStack_24;
  
  if (*(ushort *)(param_1 + 2) < 0xfff8) {
    uStack_50 = 0;
    uStack_4c = 0;
    auStack_48[0] = 0;
    auStack_48[1] = 0;
    auStack_48[2] = 0;
    auStack_48[3] = 0;
    uStack_38 = 0;
    iVar1 = zmsg_get_offset(param_2);
    uVar2 = iVar1 + 1U & 0xffff;
    iVar1 = zmsg_get_length(param_2);
    if ((int)(iVar1 - uVar2) < 0x19) {
      uVar5 = 0;
      iVar1 = 0x10;
    }
    else {
      iVar1 = zmsg_read_bytes(param_2,uVar2,1,auStack_48);
      uVar2 = uVar2 + iVar1 & 0xffff;
      iVar1 = zmsg_read_bytes(param_2,uVar2,8,&uStack_50);
      if ((auStack_48[0] & 0xff) == 3) {
        iVar1 = aps_secur_is_tc();
        if (iVar1 != 0) {
          uVar5 = 0xa3;
          iVar1 = 0;
          goto _L0;
        }
        iVar1 = aps_secur_is_addr_tc(&uStack_50);
        if (iVar1 != 0) {
          uVar5 = 0xa3;
          iVar1 = 0;
          goto _L0;
        }
      }
      else if ((auStack_48[0] & 0xff) == 4) {
        iVar3 = aps_secur_is_tc();
        if (iVar3 == 0) {
          uVar5 = 0xa3;
          iVar1 = 0;
        }
        else {
          iVar3 = aps_secur_get_key_pair_by_addr(&uStack_50);
          if (iVar3 == 0) {
            uVar5 = 0xad;
            iVar1 = 0;
          }
          else {
            uVar4 = *(ushort *)(iVar3 + 0x34) & 6;
            if ((uVar4 == 2) || (uVar4 == 4)) {
              aps_secur_key_pair_get_hash(iVar3,auStack_60);
              iVar1 = zmsg_compare_bytes(param_2,uVar2 + iVar1 & 0xffff,auStack_60,0x10);
              if (iVar1 == 0) {
                uVar5 = 0xad;
                iVar1 = 0;
              }
              else {
                if ((*(ushort *)(iVar3 + 0x34) & 6) == 2) {
                  aps_secur_key_pair_set_verified(iVar3);
                }
                apsme_verify_key_indication(&uStack_50);
                uVar5 = 0;
                iVar1 = 0;
              }
            }
            else {
              uVar5 = 0xad;
              iVar1 = 0;
            }
          }
        }
        goto _L0;
      }
      uVar5 = 0xaa;
      iVar1 = 0;
    }
  }
  else {
    uVar5 = 0;
    iVar1 = 0x12;
  }
_L0:
  if (param_2 != 0) {
    zmsg_free(param_2);
  }
  if (iVar1 == 0) {
    uStack_28 = 0;
    uStack_24 = 0;
    uStack_34 = uStack_50;
    uStack_30 = uStack_4c;
    uStack_2c = (uint)CONCAT11(uVar5,(undefined1)auStack_48[0]);
    apsme_confirm_key_request(&uStack_34);
  }
  return;
}

