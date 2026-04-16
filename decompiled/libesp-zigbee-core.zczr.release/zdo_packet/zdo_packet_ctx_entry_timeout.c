/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_packet.o -> zdo_packet_ctx_entry_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zdo_packet_ctx_entry_timeout(zdo_packet_ctx_entry_t *ent)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = core_globals_get();
  piVar2 = *(int **)(iVar1 + 0xd10);
  if (piVar2 != (int *)0x0) {
    for (; (zdo_packet_ctx_entry_t *)(piVar2 + -9) != (zdo_packet_ctx_entry_t *)0xffffffdc;
        piVar2 = (int *)*piVar2) {
      if ((zdo_packet_ctx_entry_t *)(piVar2 + -9) == ent) {
        if ((*(uint *)&ent->field_0x14 & 1) == 0) {
          zdo_packet_notify_result(&ent->ctx,7,(void *)0x0);
          ent->field_0x14 = ent->field_0x14 | 1;
        }
        else if ((ent->ctx).mode == '\x02') {
          zdo_packet_notify_result(&ent->ctx,0,(void *)0x0);
        }
        zdo_packet_ctx_list_remove_entry(ent);
        if (ent == (zdo_packet_ctx_entry_t *)0x0) {
          return;
        }
        if ((*(uint *)&ent->field_0x14 & 3) != 3) {
          return;
        }
        milli_timer_stop(&ent->timer);
        mm_free(ent);
        return;
      }
    }
  }
  return;
}

