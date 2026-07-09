/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_commands.o -> aps_cmd_handle_request_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_cmd_handle_request_key(undefined2 *param_1,int param_2)

{
  short sVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined1 uStack_14;
  
  iVar3 = aps_secur_is_tc();
  if (iVar3 != 0) {
    if ((*(ushort *)(param_2 + 0x16) & 4) == 0) goto _L0;
    uStack_24 = 0;
    uStack_20 = 0;
    uStack_1c = 0;
    uStack_18 = 0;
    uStack_14 = 0;
    sVar1 = zmsg_get_offset(param_2);
    iVar3 = nwk_address_extended_by_short(*param_1,&uStack_24);
    if (iVar3 == 0) {
      sVar2 = zmsg_read_bytes(param_2,sVar1 + 1,1,&uStack_1c);
      uVar4 = (uint)(ushort)(sVar2 + sVar1 + 1);
      if ((uStack_1c & 0xff) == 2) {
        iVar3 = zmsg_get_length(param_2);
        if (7 < (int)(iVar3 - uVar4)) {
          zmsg_read_bytes(param_2,uVar4,8,(int)&uStack_1c + 1);
          goto _L0;
        }
      }
      else if ((uStack_1c & 0xff) == 4) {
_L0:
        apsme_request_key_indication(&uStack_24);
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

