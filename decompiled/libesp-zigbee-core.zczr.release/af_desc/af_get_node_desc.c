/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> af_desc.o -> af_get_node_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

af_node_desc_t * af_get_node_desc(void)

{
  undefined2 uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = core_globals_get();
  *(undefined2 *)(iVar3 + 0xcec) = 0;
  uVar2 = nwk_get_device_type();
  *(ushort *)(iVar3 + 0xcec) = *(ushort *)(iVar3 + 0xcec) | uVar2 & 7;
  iVar4 = core_globals_get();
  if (*(char *)(iVar4 + 0x18) < '\0') {
    uVar2 = *(ushort *)(iVar3 + 0xcec) | 0x20;
  }
  else {
    uVar2 = *(ushort *)(iVar3 + 0xcec) & 0xffdf;
  }
  *(ushort *)(iVar3 + 0xcec) = uVar2 & 0x7ff | 0x4000;
  *(undefined1 *)(iVar3 + 0xcee) = 0x80;
  iVar4 = nwk_is_device_zczr();
  if (iVar4 != 0) {
    *(byte *)(iVar3 + 0xcee) = *(byte *)(iVar3 + 0xcee) | 2;
  }
  iVar4 = core_globals_get();
  if (*(char *)(iVar4 + 0x9ee) != '\0') {
    *(byte *)(iVar3 + 0xcee) = *(byte *)(iVar3 + 0xcee) | 8;
  }
  iVar4 = core_globals_get();
  if ((*(ushort *)(iVar4 + 0xcfc) & 0xf00) == 0x100) {
    *(byte *)(iVar3 + 0xcee) = *(byte *)(iVar3 + 0xcee) | 4;
  }
  *(undefined1 *)(iVar3 + 0xcf2) = 0x6c;
  iVar4 = core_globals_get();
  uVar1 = *(undefined2 *)(iVar4 + 4);
  *(undefined2 *)(iVar3 + 0xcf4) = uVar1;
  *(undefined2 *)(iVar3 + 0xcf8) = uVar1;
  *(undefined2 *)(iVar3 + 0xcf6) = 0x2c00;
  iVar4 = nwk_is_device_zc();
  if (iVar4 != 0) {
    *(ushort *)(iVar3 + 0xcf6) = *(ushort *)(iVar3 + 0xcf6) | 0x41;
  }
  iVar3 = core_globals_get();
  return (af_node_desc_t *)(iVar3 + 0xcec);
}

