/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_commands.o -> apsme_confirm_key_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int apsme_confirm_key_request(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  iVar1 = 2;
  if (param_1 != (undefined4 *)0x0) {
    iVar2 = ezb_eui64_is_invalid();
    iVar1 = 2;
    if (iVar2 == 0) {
      if (*(char *)(param_1 + 2) == '\x03') {
        iVar1 = aps_secur_is_addr_tc(param_1);
        if (iVar1 != 0) {
          return 0x3a6;
        }
      }
      else if (*(char *)(param_1 + 2) == '\x04') {
        iVar1 = aps_secur_is_tc();
        if (iVar1 == 0) {
          return 0x3a3;
        }
        iVar1 = zmsg_alloc(0x3c);
        if (iVar1 == 0) {
          return 1;
        }
        aps_frame_append_cmd_hdr(0,1,1,0);
        zmsg_append_u8_isra_0(iVar1,0x10);
        zmsg_append_u8_isra_0(iVar1,*(undefined1 *)((int)param_1 + 9));
        zmsg_append_u8_isra_0(iVar1,*(undefined1 *)(param_1 + 2));
        uStack_18 = *param_1;
        uStack_14 = param_1[1];
        zmsg_append_bytes(iVar1,8,&uStack_18);
        iVar2 = aps_send_cmd(iVar1,param_1);
        if (iVar2 == 0) {
          return 0;
        }
        zmsg_free(iVar1);
        return iVar2;
      }
      iVar1 = 0x3aa;
    }
  }
  return iVar1;
}

