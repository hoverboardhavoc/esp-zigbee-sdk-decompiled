/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_packet.o -> zdo_packet_ctx_entry_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zdo_packet_ctx_entry_timeout(zdo_packet_ctx_entry_t *ent)

{
  undefined4 *puVar1;
  zdo_packet_ctx_entry_t *ent_00;
  int iVar2;
  
  iVar2 = core_globals_get();
  puVar1 = *(undefined4 **)(iVar2 + 0xcac);
  if (puVar1 != (undefined4 *)0x0) {
    for (; (ent_00 = (zdo_packet_ctx_entry_t *)(puVar1 + -9),
           ent_00 != (zdo_packet_ctx_entry_t *)0xffffffdc &&
           ((ent_00 == (zdo_packet_ctx_entry_t *)0x0 || (ent_00 != ent))));
        puVar1 = (undefined4 *)*puVar1) {
    }
    if ((ent_00 != (zdo_packet_ctx_entry_t *)0xffffffdc) &&
       (ent_00 != (zdo_packet_ctx_entry_t *)0x0)) {
      if ((puVar1[-4] & 1) == 0) {
        zdo_packet_notify_result((zdo_packet_ctx_t *)(puVar1 + -3),7,(void *)0x0);
        *(byte *)(puVar1 + -4) = *(byte *)(puVar1 + -4) | 1;
      }
      else if (*(char *)(puVar1 + -3) == '\x02') {
        zdo_packet_notify_result((zdo_packet_ctx_t *)(puVar1 + -3),0,(void *)0x0);
      }
      zdo_packet_ctx_list_remove_entry(ent_00);
      zdo_packet_ctx_free_entry(ent_00);
    }
  }
  return;
}

