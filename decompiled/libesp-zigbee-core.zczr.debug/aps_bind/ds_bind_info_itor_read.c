/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> ds_bind_info_itor_read
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ds_bind_info_itor_read(ds_bind_info_iterator_t *itor)

{
  int iVar1;
  
  *(undefined1 *)&(itor->data).cluster_id = 0;
  *(undefined1 *)((int)&(itor->data).cluster_id + 1) = 0;
  (itor->data).src_ep = '\0';
  (itor->data).dst_ep = '\0';
  *(undefined1 *)&(itor->data).field_3 = 0;
  *(undefined1 *)((int)&(itor->data).field_3 + 1) = 0;
  *(undefined1 *)((int)&(itor->data).field_3 + 2) = 0;
  *(undefined1 *)((int)&(itor->data).field_3 + 3) = 0;
  *(undefined1 *)((int)&(itor->data).field_3 + 4) = 0;
  *(undefined1 *)((int)&(itor->data).field_3 + 5) = 0;
  *(undefined1 *)((int)&(itor->data).field_3 + 6) = 0;
  *(undefined1 *)((int)&(itor->data).field_3 + 7) = 0;
  iVar1 = ds_internal_read_entry(6,itor->index,itor,0xc);
  itor->is_done = iVar1 != 0;
  return;
}

