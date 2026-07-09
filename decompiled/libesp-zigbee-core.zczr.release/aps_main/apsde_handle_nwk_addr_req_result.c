/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_main.o -> apsde_handle_nwk_addr_req_result
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void apsde_handle_nwk_addr_req_result(int param_1,int param_2)

{
  int unaff_s0;
  int iVar1;
  char *pcVar2;
  undefined1 auStack_2c [4];
  char cStack_28;
  
  if ((param_1 != 0) && (unaff_s0 = param_2, param_2 != 0)) goto _L0;
  do {
    param_1 = __assert_func(0,0,0,0);
_L0:
    memset(auStack_2c,0,0x1c);
    zmsg_get_footer(unaff_s0,auStack_2c,0x1c);
    zmsg_remove_footer(unaff_s0,0x1c);
  } while (cStack_28 != '\x03');
  pcVar2 = *(char **)(param_1 + 4);
  if (pcVar2 == (char *)0x0) {
    iVar1 = 0x3a9;
  }
  else {
    iVar1 = 0x3a9;
    if ((*pcVar2 == '\0') &&
       (iVar1 = apsde_data_request_continue(auStack_2c,*(undefined2 *)(pcVar2 + 10)), iVar1 == 0)) {
      return;
    }
  }
  zmsg_add_footer(unaff_s0,auStack_2c,0x1c);
  zmsg_set_offset(unaff_s0,0);
  aps_send_data_confirm(unaff_s0,iVar1);
  return;
}

