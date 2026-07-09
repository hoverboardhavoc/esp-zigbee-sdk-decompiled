/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_fwd_handle_nwk_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_fwd_handle_nwk_confirm(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  ushort uStack_1c;
  undefined1 auStack_1a [2];
  undefined4 uStack_18;
  byte bStack_11;
  
  iVar1 = *param_1;
  if (*(byte *)(param_1 + 1) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(byte *)(param_1 + 1) | 0x100;
  }
  iVar2 = nwk_process_receive_security(iVar1);
  if (iVar2 == 0) {
    zmsg_read_bytes(iVar1,4,2,auStack_1a);
    zmsg_read_bytes(iVar1,2,&uStack_1c);
    if ((((uint)param_1[1] >> 8 & 1) == 0) &&
       ((0xfff7 < uStack_1c ||
        ((uVar3 - 0x1e1 < 0x11 && ((0x10101U >> (uVar3 - 0x1e1 & 0x1f) & 1) != 0)))))) {
      nwk_fwd_get_retry_params(iVar1,&bStack_11,&uStack_18);
      goto _L0;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_forwarder.c",0x3bd,
                  "nwk_fwd_handle_nwk_confirm","(nwk_process_receive_security(iface_id, msg)) == 0")
    ;
  }
  bStack_11 = 0;
_L0:
  if (*(byte *)(iVar1 + 0x14) < bStack_11) {
    *(byte *)(iVar1 + 0x14) = *(byte *)(iVar1 + 0x14) + 1;
    nwk_fwd_retry(iVar1,uStack_18);
  }
  else {
    if ((((uint)param_1[1] >> 8 & 1) != 0) && (0xfff7 < uStack_1c)) {
      zmsg_free(iVar1);
      return;
    }
    nwk_fwd_finish_tx(iVar1,uVar3);
  }
  return;
}

