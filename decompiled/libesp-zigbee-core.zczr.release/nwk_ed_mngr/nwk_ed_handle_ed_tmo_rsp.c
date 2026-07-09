/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_ed_mngr.o -> nwk_ed_handle_ed_tmo_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_ed_handle_ed_tmo_rsp(int param_1,int param_2)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  char cStack_14;
  undefined1 uStack_13;
  
  iVar3 = nwk_is_device_zed();
  if ((iVar3 == 0) || (iVar3 = nwk_is_joined(), iVar3 == 0)) {
    if (param_1 == 0) {
      return;
    }
  }
  else {
    iVar3 = nwk_secur_get_seclevel();
    if (((ushort)(iVar3 != 0) == (*(ushort *)(param_1 + 0x16) >> 1 & 1)) &&
       (uVar1 = *(ushort *)(param_2 + 2), uVar4 = nwk_get_parent_shortaddr(), uVar1 == uVar4)) {
      nwk_pim_stop_fast_poll();
      sVar2 = zmsg_get_offset(param_1);
      zmsg_read_bytes(param_1,sVar2 + 1,2,&cStack_14);
      if (cStack_14 == '\0') {
        iVar3 = core_globals_get();
        *(undefined1 *)(iVar3 + 0xa28) = uStack_13;
        iVar3 = core_globals_get();
        *(byte *)(iVar3 + 0xaf8) = *(byte *)(iVar3 + 0xaf8) | 0x40;
      }
      nwk_ed_process_keepalive_result(cStack_14 == '\0');
    }
  }
  zmsg_free(param_1);
  return;
}

