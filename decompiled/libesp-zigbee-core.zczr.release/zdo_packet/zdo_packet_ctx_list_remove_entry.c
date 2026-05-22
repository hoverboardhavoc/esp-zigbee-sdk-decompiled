/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> zdo_packet.o -> zdo_packet_ctx_list_remove_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zdo_packet_ctx_list_remove_entry(zdo_packet_ctx_entry_t *ent)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = core_globals_get();
  piVar2 = *(int **)(iVar1 + 0xcac);
  if (piVar2 != (int *)0x0) {
    for (; (zdo_packet_ctx_entry_t *)(piVar2 + -9) != (zdo_packet_ctx_entry_t *)0xffffffdc;
        piVar2 = (int *)*piVar2) {
      if ((zdo_packet_ctx_entry_t *)(piVar2 + -9) == ent) {
        iVar1 = core_globals_get();
        list_remove_node(iVar1 + 0xcac,piVar2);
        if (*(char *)(piVar2 + -3) == '\0') {
          return;
        }
        nwk_pim_stop_fast_poll();
        return;
      }
    }
  }
  return;
}

