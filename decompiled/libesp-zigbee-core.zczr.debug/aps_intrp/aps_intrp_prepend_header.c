/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_intrp.o -> aps_intrp_prepend_header
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_intrp_prepend_header(int param_1,int param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  byte bVar3;
  undefined1 *puVar4;
  undefined4 uStack_18;
  undefined2 uStack_14;
  undefined1 uStack_12;
  
  uStack_18 = 0;
  uStack_14 = 0;
  uStack_12 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    param_2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/interpan/aps_intrp.c",
                            0x34,"aps_intrp_prepend_header","msg && req");
  }
  else {
    if (*(char *)(param_2 + 4) == '\x01') {
      bVar3 = 0xf;
      goto _L0;
    }
    if (*(char *)(param_2 + 4) != '\x02') {
      bVar3 = 3;
      goto _L0;
    }
  }
  if (*(ushort *)(param_2 + 6) < 0xfff8) {
    bVar3 = 3;
  }
  else {
    bVar3 = 0xb;
  }
_L0:
  uVar2 = uStack_18;
  uStack_18 = CONCAT31(uStack_18._1_3_,bVar3);
  if ((bVar3 & 0xc) == 0xc) {
    uStack_18._3_1_ = SUB41(uVar2,3);
    uStack_18._0_3_ =
         CONCAT12((char)((ushort)*(undefined2 *)(param_2 + 6) >> 8),
                  CONCAT11((char)*(undefined2 *)(param_2 + 6),bVar3));
    puVar4 = (undefined1 *)((int)&uStack_18 + 3);
  }
  else {
    puVar4 = (undefined1 *)((int)&uStack_18 + 1);
  }
  uVar1 = *(undefined2 *)(param_2 + 0x10);
  *puVar4 = (char)uVar1;
  puVar4[1] = (char)((ushort)uVar1 >> 8);
  uVar1 = *(undefined2 *)(param_2 + 0xe);
  puVar4[2] = (char)uVar1;
  puVar4[3] = (char)((ushort)uVar1 >> 8);
  zmsg_prepend_bytes((uint)(puVar4 + (4 - (int)&uStack_18)) & 0xffff);
  return;
}

