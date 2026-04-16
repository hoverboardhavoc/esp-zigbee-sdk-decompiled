/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_route_table.o -> nwk_route_record_table_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_route_record_table_init(uint16_t capacity)

{
  undefined2 uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar3 = core_globals_get();
  iVar3 = *(int *)(iVar3 + 0xcd4);
  iVar4 = core_globals_get();
  iVar6 = *(int *)(iVar4 + 0xcd8);
  iVar4 = core_globals_get();
  if (((*(short *)(iVar4 + 0xcdc) != 0) && (iVar3 != 0)) && (iVar6 != 0)) {
    __assert_func("//build/esp-zigbee/src/core/nwk/nwk_route_table.c",0x212,
                  "nwk_route_record_table_init",&_LC9);
  }
  iVar3 = core_globals_get();
  *(undefined1 *)(iVar3 + 0xcd4) = 0;
  *(undefined1 *)(iVar3 + 0xcd5) = 0;
  *(undefined1 *)(iVar3 + 0xcd6) = 0;
  *(undefined1 *)(iVar3 + 0xcd7) = 0;
  *(undefined1 *)(iVar3 + 0xcd8) = 0;
  *(undefined1 *)(iVar3 + 0xcd9) = 0;
  *(undefined1 *)(iVar3 + 0xcda) = 0;
  *(undefined1 *)(iVar3 + 0xcdb) = 0;
  *(undefined1 *)(iVar3 + 0xcdc) = 0;
  *(undefined1 *)(iVar3 + 0xcdd) = 0;
  *(undefined1 *)(iVar3 + 0xcde) = 0;
  *(undefined1 *)(iVar3 + 0xcdf) = 0;
  iVar3 = core_globals_get();
  *(uint16_t *)(iVar3 + 0xcdc) = capacity;
  iVar3 = core_globals_get();
  uVar1 = *(undefined2 *)(iVar3 + 0xcdc);
  iVar3 = core_globals_get();
  uVar5 = mm_calloc(uVar1,0x1c);
  *(undefined4 *)(iVar3 + 0xcd4) = uVar5;
  iVar3 = core_globals_get();
  uVar2 = *(ushort *)(iVar3 + 0xcdc);
  iVar3 = core_globals_get();
  uVar5 = mm_calloc(uVar2 + 7 >> 3,1);
  *(undefined4 *)(iVar3 + 0xcd8) = uVar5;
  return;
}

