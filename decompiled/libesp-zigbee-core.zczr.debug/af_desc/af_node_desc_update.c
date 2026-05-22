/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_node_desc_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void af_node_desc_update(void)

{
  undefined2 uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = core_globals_get();
  *(undefined2 *)(iVar3 + 0xc88) = 0;
  uVar2 = nwk_get_device_type();
  *(ushort *)(iVar3 + 0xc88) = *(ushort *)(iVar3 + 0xc88) | uVar2 & 7;
  iVar4 = core_globals_get();
  if (*(char *)(iVar4 + 0x18) < '\0') {
    *(ushort *)(iVar3 + 0xc88) = *(ushort *)(iVar3 + 0xc88) | 0x20;
  }
  else {
    *(ushort *)(iVar3 + 0xc88) = *(ushort *)(iVar3 + 0xc88) & 0xffdf;
  }
  uVar2 = *(ushort *)(iVar3 + 0xc88) & 0x7ff;
  *(ushort *)(iVar3 + 0xc88) = uVar2;
  *(ushort *)(iVar3 + 0xc88) = uVar2 | 0x4000;
  *(undefined1 *)(iVar3 + 0xc8a) = 0x80;
  iVar4 = nwk_is_device_zczr();
  if (iVar4 != 0) {
    *(byte *)(iVar3 + 0xc8a) = *(byte *)(iVar3 + 0xc8a) | 2;
  }
  iVar4 = core_globals_get();
  if (*(char *)(iVar4 + 0x9ee) != '\0') {
    *(byte *)(iVar3 + 0xc8a) = *(byte *)(iVar3 + 0xc8a) | 8;
  }
  iVar4 = core_globals_get();
  if ((*(ushort *)(iVar4 + 0xc98) & 0xf00) == 0x100) {
    *(byte *)(iVar3 + 0xc8a) = *(byte *)(iVar3 + 0xc8a) | 4;
  }
  *(undefined1 *)(iVar3 + 0xc8e) = 0x6c;
  iVar4 = core_globals_get();
  uVar1 = *(undefined2 *)(iVar4 + 4);
  *(undefined2 *)(iVar3 + 0xc90) = uVar1;
  *(undefined2 *)(iVar3 + 0xc94) = uVar1;
  *(undefined2 *)(iVar3 + 0xc92) = 0x2c00;
  iVar4 = nwk_is_device_zc();
  if (iVar4 != 0) {
    uVar2 = *(ushort *)(iVar3 + 0xc92);
    *(ushort *)(iVar3 + 0xc92) = uVar2 | 1;
    *(ushort *)(iVar3 + 0xc92) = uVar2 | 0x41;
  }
  return;
}

