/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_multimac.o -> nwk_mm_register_interface
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_mm_register_interface(nwk_mac_iface_config_t *config,uint8_t *iface_id)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = core_globals_get();
  bVar1 = (*(uint *)(iVar2 + 0xc7c) >> 5 & 3) != 0;
  if (!bVar1) {
    iVar2 = core_globals_get();
    *iface_id = '\0';
    uVar3 = *(uint *)&config->field_0x4;
    *(mac_interface_t **)(iVar2 + 0xc84) = config->iface;
    *(ushort *)(iVar2 + 0xc7c) =
         (ushort)((uVar3 & 1) << 7) | 0x20 | (ushort)(uVar3 << 7) & 0x100 |
         (ushort)(uVar3 << 7) & 0x200 | (ushort)(uVar3 << 7) & 0x400 |
         (ushort)((uVar3 >> 4 & 1) << 0xb) | *(ushort *)(iVar2 + 0xc7c) & 0xf000;
  }
  return (uint)bVar1;
}

