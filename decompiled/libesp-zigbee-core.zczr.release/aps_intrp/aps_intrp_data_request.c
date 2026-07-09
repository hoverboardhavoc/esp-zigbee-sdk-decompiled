/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_intrp.o -> aps_intrp_data_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_intrp_data_request(int param_1,uint param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  void *__src;
  undefined1 *puVar4;
  byte bVar5;
  undefined4 uStack_2c;
  undefined2 uStack_28;
  undefined1 uStack_26;
  undefined2 uStack_22;
  undefined1 auStack_20 [12];
  undefined4 uStack_14;
  
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_26 = 0;
  if (*(int *)(param_1 + 0x14) == 0) {
    __assert_func(0,0,0,0);
  }
  else {
    param_2 = (uint)*(byte *)(param_1 + 4);
    bVar5 = 0xf;
    if (param_2 == 1) goto _L0;
  }
  bVar5 = 3;
  if (param_2 == 2) {
    bVar5 = (0xfff7 < *(ushort *)(param_1 + 6)) * '\b' + 3;
  }
_L0:
  uVar2 = uStack_2c;
  uStack_2c = CONCAT31(uStack_2c._1_3_,bVar5);
  puVar4 = (undefined1 *)((int)&uStack_2c + 1);
  if ((bVar5 & 0xc) == 0xc) {
    puVar4 = (undefined1 *)((int)&uStack_2c + 3);
    uStack_2c._3_1_ = SUB41(uVar2,3);
    uStack_2c._0_3_ =
         CONCAT12((char)((ushort)*(undefined2 *)(param_1 + 6) >> 8),
                  CONCAT11((char)*(undefined2 *)(param_1 + 6),bVar5));
  }
  uVar1 = *(undefined2 *)(param_1 + 0x10);
  *puVar4 = (char)uVar1;
  puVar4[1] = (char)((ushort)uVar1 >> 8);
  uVar1 = *(undefined2 *)(param_1 + 0xe);
  puVar4[2] = (char)uVar1;
  puVar4[3] = (char)((ushort)uVar1 >> 8);
  iVar3 = zmsg_prepend_bytes((uint)(puVar4 + (4 - (int)&uStack_2c)) & 0xffff,&uStack_2c);
  if (iVar3 == 0) {
    uStack_2c = CONCAT31(uStack_2c._1_3_,3);
    __src = (void *)nwk_get_extended_address();
    memcpy((void *)((int)&uStack_2c + 2),__src,8);
    uStack_22 = *(undefined2 *)(param_1 + 2);
    memcpy(auStack_20,(void *)(param_1 + 4),10);
    uStack_14 = *(undefined4 *)(param_1 + 0x14);
    iVar3 = zmsg_add_footer(param_1,0x18);
    if (iVar3 == 0) {
      nwk_intrp_data_request(&uStack_2c);
    }
  }
  return;
}

