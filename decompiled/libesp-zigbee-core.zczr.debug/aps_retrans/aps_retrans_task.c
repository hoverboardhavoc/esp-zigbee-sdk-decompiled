/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_retrans.o -> aps_retrans_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_retrans_task(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = zmsg_queue_get_head(param_1 + 0x10);
  if ((iVar1 != 0) && (iVar2 = aps_retrans_ent_new(param_1), iVar2 != 0)) {
    zmsg_queue_dequeue(param_1 + 0x10,iVar1);
    iVar3 = core_globals_get();
    aps_retrans_ent_init(iVar2,*(undefined1 *)(iVar3 + 2));
    aps_retrans_ent_set_msg(iVar2,iVar1);
    aps_retrans_send(iVar2);
    tasklet_post(param_1);
  }
  return;
}

