/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_secur_unsecure_msg_by_key_pair
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int aps_secur_unsecure_msg_by_key_pair(int param_1,undefined4 param_2,byte *param_3)

{
  uint uVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  byte bStack_34;
  char acStack_30 [28];
  
  uVar1 = *(uint *)(param_3 + 1);
  aps_secur_key_pair_get_key(acStack_30,*param_3 & 0x18);
  uVar5 = 0x10;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1 & 0xff;
  } while (acStack_30[uVar5] == '\0');
  if (uVar5 == 0) {
    iVar4 = 0x13;
  }
  else {
    local_40 = *(undefined4 *)(param_3 + 5);
    uStack_3c = *(undefined4 *)(param_3 + 9);
    uStack_38 = *(undefined4 *)(param_3 + 1);
    bStack_34 = *param_3;
    bVar2 = bStack_34 & 7;
    uVar3 = zmsg_get_offset(param_2);
    iVar4 = secur_unsecure_msg(bVar2,acStack_30,&local_40,param_2,uVar3);
    if (iVar4 == 0) {
      if (uVar1 < *(uint *)(param_1 + 0xc)) {
        iVar4 = 0x13;
      }
      else {
        *(uint *)(param_1 + 0xc) = uVar1 + 1;
      }
    }
  }
  return iVar4;
}

