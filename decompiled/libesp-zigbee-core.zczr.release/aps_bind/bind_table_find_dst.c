/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_bind.o -> bind_table_find_dst
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

ushort * bind_table_find_dst(char *param_1,uint param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  ushort *puVar7;
  int iStack_38;
  uint uStack_34;
  
  iVar2 = core_globals_get();
  uVar4 = 0;
  do {
    uVar4 = bitmap_find_next_bit
                      (*(undefined4 *)(iVar2 + 0x978),*(undefined2 *)(iVar2 + 0x97c),uVar4);
    if (*(ushort *)(iVar2 + 0x97c) <= uVar4) {
      return (ushort *)0x0;
    }
    cVar1 = *param_1;
    puVar7 = (ushort *)(*(int *)(iVar2 + 0x974) + uVar4 * 6);
    if ((ushort)(cVar1 == '\x01') != (puVar7[2] >> 8 & 1)) goto _L0;
    if (cVar1 == '\x01') {
_L0:
      uVar6 = (uint)*(ushort *)(param_1 + 2);
      uVar5 = (uint)*puVar7;
_L0:
      if (uVar5 == uVar6) {
        return puVar7;
      }
    }
    else {
      if (cVar1 != '\x03') {
_L0:
        __assert_func(0,0,0,0);
        goto _L0;
      }
      if ((param_2 == 0xff) || ((byte)puVar7[1] == param_2)) {
        iVar3 = nwk_address_extended_by_ref(*puVar7,&iStack_38);
        if (iVar3 != 0) goto _L0;
        uVar6 = *(uint *)(param_1 + 6);
        uVar5 = uStack_34;
        if (iStack_38 != *(int *)(param_1 + 2)) goto _L0;
        goto _L0;
      }
    }
_L0:
    uVar4 = uVar4 + 1 & 0xffff;
  } while( true );
}

