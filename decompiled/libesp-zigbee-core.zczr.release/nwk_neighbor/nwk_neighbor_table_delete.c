/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> nwk_neighbor.o -> nwk_neighbor_table_delete
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_neighbor_table_delete(short *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar3 = core_globals_get();
  uVar1 = ((int)param_1 - *(int *)(iVar3 + 0xb20) >> 2) * -0x49249249;
  if ((uVar1 & 0xffff) < (uint)*(ushort *)(iVar3 + 0xb24)) goto _L171;
  do {
    while( true ) {
      do {
        iVar3 = __assert_func(0,0,0,0);
_L171:
        if (*param_1 != -1) {
          nwk_address_unlock_ref();
        }
        uVar5 = 1 << (uVar1 & 7) & 0xff;
        uVar1 = (uVar1 << 0x10) >> 0x13;
        uVar4 = __atomic_fetch_and_1(*(int *)(iVar3 + 0xb1c) + uVar1,~uVar5 & 0xff,5);
      } while ((uVar5 & uVar4) == 0);
      iVar2 = *(int *)(iVar3 + 0xb20);
      uVar4 = nwk_neighbor_table_get_router_capacity();
      uVar1 = ((int)param_1 - iVar2 >> 2) * -0x49249249 & 0xffff;
      if (uVar1 < uVar4) break;
      if ((*(uint *)(param_1 + 6) & 3) == 2) {
        nwk_neighbor_table_remove_stored_child(param_1);
        if (*(short *)(iVar3 + 0xb28) != 0) {
          *(short *)(iVar3 + 0xb28) = *(short *)(iVar3 + 0xb28) + -1;
          nwk_update_beacon_payload();
          return;
        }
      }
    }
  } while ((1 < (*(uint *)(param_1 + 6) & 3)) || (*(short *)(iVar3 + 0xb2a) == 0));
  *(short *)(iVar3 + 0xb2a) = *(short *)(iVar3 + 0xb2a) + -1;
  return;
}

