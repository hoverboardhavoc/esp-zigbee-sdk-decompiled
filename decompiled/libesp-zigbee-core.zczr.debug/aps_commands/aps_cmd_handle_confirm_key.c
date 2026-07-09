/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_commands.o -> aps_cmd_handle_confirm_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_cmd_handle_confirm_key(undefined2 *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  int iStack_14;
  
  if (((ushort)param_1[1] < 0xfff8) && (iVar1 = aps_secur_is_tc(), iVar1 == 0)) {
    if ((*(ushort *)(param_2 + 0x16) & 4) == 0) goto _L0;
    uStack_2c = 0;
    uStack_28 = 0;
    uStack_24 = 0;
    uStack_20 = 0;
    uStack_1c = 0;
    iVar1 = zmsg_get_offset(param_2);
    uVar3 = iVar1 + 1U & 0xffff;
    iVar1 = nwk_address_extended_by_short(*param_1,&uStack_2c);
    if ((iVar1 == 0) && (iVar1 = zmsg_get_length(param_2), 9 < (int)(iVar1 - uVar3))) {
      iVar1 = zmsg_read_bytes(param_2,uVar3,1,(int)&uStack_24 + 1);
      uVar3 = uVar3 + iVar1 & 0xffff;
      iVar1 = zmsg_read_bytes(param_2,uVar3,1,&uStack_24);
      zmsg_read_bytes(param_2,uVar3 + iVar1 & 0xffff,8,&iStack_18);
      piVar2 = (int *)nwk_get_extended_address();
      if (((iStack_18 == *piVar2) &&
          (((iStack_14 == piVar2[1] && ((uStack_24 & 0xff) == 4)) &&
           (iVar1 = aps_secur_is_addr_tc(&uStack_2c), iVar1 != 0)))) &&
         (iVar1 = aps_secur_get_key_pair_by_addr(&uStack_2c), iVar1 != 0)) {
        if ((uStack_24._1_1_ == '\0') && ((*(ushort *)(iVar1 + 0x34) & 6) == 2)) {
          aps_secur_key_pair_set_verified();
        }
        apsme_confirm_key_indication(&uStack_2c);
      }
    }
  }
  if (param_2 == 0) {
    return;
  }
_L0:
  zmsg_free(param_2);
  return;
}

