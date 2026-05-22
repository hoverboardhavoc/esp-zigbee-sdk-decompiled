/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_multimac.o -> nwk_mm_register_interface
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_mm_register_interface(nwk_mac_iface_config_t *config,uint8_t *iface_id)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  
  uVar1 = 0;
  do {
    if (uVar1 != 0) {
      puVar7 = (uint *)0x0;
_L0:
      if (puVar7 != (uint *)0x0) {
        *iface_id = (uint8_t)uVar1;
        uVar8 = *puVar7;
        *puVar7 = uVar8 & 0xffffffe0 | uVar1;
        *puVar7 = uVar8 & 0xffffff80 | uVar1 | 0x20;
        puVar7[2] = (uint)config->iface;
        uVar3 = (*(uint *)&config->field_0x4 & 1) << 7;
        *puVar7 = uVar8 & 0xffffff00 | uVar1 | 0x20 | uVar3;
        uVar4 = (*(uint *)&config->field_0x4 >> 1 & 1) << 8;
        *puVar7 = uVar8 & 0xfffffe00 | uVar1 | 0x20 | uVar3 | uVar4;
        uVar5 = (*(uint *)&config->field_0x4 >> 2 & 1) << 9;
        *puVar7 = uVar8 & 0xfffffc00 | uVar1 | 0x20 | uVar3 | uVar4 | uVar5;
        uVar6 = (*(uint *)&config->field_0x4 >> 3 & 1) << 10;
        *puVar7 = uVar8 & 0xfffff800 | uVar1 | 0x20 | uVar3 | uVar4 | uVar5 | uVar6;
        *puVar7 = uVar8 & 0xfffff000 | uVar1 | 0x20 | uVar3 | uVar4 | uVar5 | uVar6 |
                  (*(uint *)&config->field_0x4 >> 4 & 1) << 0xb;
      }
      return (uint)(puVar7 == (uint *)0x0);
    }
    iVar2 = core_globals_get();
    if ((*(uint *)(iVar2 + 0xc7c) >> 5 & 3) == 0) {
      iVar2 = core_globals_get();
      puVar7 = (uint *)(iVar2 + 0xc7c);
      goto _L0;
    }
    uVar1 = 1;
  } while( true );
}

