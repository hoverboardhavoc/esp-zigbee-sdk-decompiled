/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_commands.o -> apsme_request_key_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int apsme_request_key_request(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  if (param_1 == 0) {
    return 2;
  }
  iVar2 = ezb_eui64_is_invalid();
  iVar1 = 2;
  if (iVar2 != 0) {
    return 2;
  }
  iVar2 = zmsg_alloc(0x3c);
  if (iVar2 == 0) {
    return 1;
  }
  aps_frame_append_cmd_hdr(0,1,0);
  zmsg_append_u8_isra_0(iVar2,8);
  zmsg_append_u8_isra_0(iVar2,*(undefined1 *)(param_1 + 8));
  if (*(char *)(param_1 + 8) == '\x02') {
    iVar3 = ezb_eui64_is_invalid(param_1 + 9);
    if (iVar3 != 0) goto _L0;
    uStack_18 = *(undefined4 *)(param_1 + 9);
    uStack_14 = *(undefined4 *)(param_1 + 0xd);
    zmsg_append_bytes(iVar2,8,&uStack_18);
  }
  else if (*(char *)(param_1 + 8) != '\x04') goto _L0;
  iVar1 = aps_send_cmd(iVar2,param_1);
  if (iVar1 == 0) {
    return 0;
  }
_L0:
  zmsg_free(iVar2);
  return iVar1;
}

