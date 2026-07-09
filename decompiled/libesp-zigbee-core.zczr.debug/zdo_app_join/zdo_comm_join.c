/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_join.o -> zdo_comm_join
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_comm_join(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  byte bVar4;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined2 uStack_14;
  byte bStack_12;
  
  iVar1 = nwk_disc_table_next(0);
  if (iVar1 == 0) {
    uVar3 = 0x1ea;
  }
  else {
    uStack_1c = 0;
    uStack_18 = 0;
    uStack_14 = 0;
    bStack_12 = 0;
    iVar2 = af_get_node_desc();
    uStack_14._1_1_ = *(undefined1 *)(iVar2 + 2);
    nwk_address_get_extpanid(*(undefined1 *)(iVar1 + 8),&uStack_1c);
    iVar1 = core_globals_get();
    bVar4 = *(byte *)(iVar1 + 0xcdc) & 1;
    if ((*(byte *)(iVar1 + 0xcdc) & 1) != 0) {
      bVar4 = 2;
    }
    uStack_14 = CONCAT11(uStack_14._1_1_,bVar4);
    iVar1 = core_globals_get();
    bStack_12 = bStack_12 & 0xfe | *(char *)(iVar1 + 0xcc0) == '\x03';
    uVar3 = nwk_join_request(&uStack_1c);
  }
  return uVar3;
}

