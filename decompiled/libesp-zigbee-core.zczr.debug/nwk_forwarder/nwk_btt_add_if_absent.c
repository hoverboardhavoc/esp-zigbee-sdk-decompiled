/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_btt_add_if_absent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nwk_btt_add_if_absent(int param_1,undefined4 param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 uStack_11;
  
  zmsg_read_bytes(param_2,7,1,&uStack_11);
  uVar1 = *(undefined2 *)(param_1 + 6);
  iVar3 = nwk_btt_find(uVar1,uStack_11);
  if (iVar3 == 0) {
    iVar3 = nwk_btr_create(uVar1,uStack_11);
    if (iVar3 == 0) {
      return 0;
    }
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  nwk_btr_set_passive_ack(*(undefined2 *)(param_1 + 2));
  return uVar2;
}

