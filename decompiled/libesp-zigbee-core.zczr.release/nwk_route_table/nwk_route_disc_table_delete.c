/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_route_table.o -> nwk_route_disc_table_delete
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_route_disc_table_delete(nwk_route_disc_t *route_disc)

{
  byte bVar1;
  ushort uVar2;
  ezb_shortaddr_t eVar3;
  nwk_route_t *obj;
  uint uVar4;
  int iVar5;
  bitmap_t *pbVar6;
  uint8_t uVar7;
  void *pvVar8;
  
  obj = route_disc->route;
  uVar2 = route_disc->src_addr;
  uVar4 = nwk_get_short_address();
  iVar5 = core_globals_get();
  pvVar8 = *(void **)(iVar5 + 0xc64);
  iVar5 = core_globals_get();
  pbVar6 = *(bitmap_t **)(iVar5 + 0xc68);
  iVar5 = core_globals_get();
  mempool_free_ent(pvVar8,pbVar6,0x10,*(uint16_t *)(iVar5 + 0xc6c),route_disc);
  if (obj != (nwk_route_t *)0x0) {
    if (uVar2 != uVar4) goto _L0;
    uVar7 = obj->initiator;
    if (uVar7 != '\0') goto _L0;
    do {
      __assert_func(0,0,0,0);
_L0:
      obj->initiator = uVar7 + 0xff;
_L0:
      uVar7 = obj->ref;
    } while (uVar7 == '\0');
    obj->ref = uVar7 + 0xff;
    if ((uVar7 == '\x01') && ((*(ushort *)&obj->field_0xe & 7) != 0)) {
      bVar1 = obj->field_0xf;
      eVar3 = obj->dst_addr;
      iVar5 = core_globals_get();
      pvVar8 = *(void **)(iVar5 + 0xc58);
      iVar5 = core_globals_get();
      pbVar6 = *(bitmap_t **)(iVar5 + 0xc5c);
      iVar5 = core_globals_get();
      mempool_free_ent(pvVar8,pbVar6,0x10,*(uint16_t *)(iVar5 + 0xc60),obj);
      nwk_fwd_handle_route_disc_done(eVar3,0x2d0);
      if ((bVar1 & 1) != 0) {
        nwk_mesh_route_discovery_done(eVar3,0x2d0,0);
        return;
      }
    }
  }
  return;
}

