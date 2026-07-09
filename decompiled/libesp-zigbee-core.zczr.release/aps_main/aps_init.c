/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_main.o -> aps_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_init(void)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  
  random_init();
  aps_secur_init();
  puVar2 = (undefined1 *)core_globals_get();
  uVar1 = random_noncrypto_get_u32();
  *puVar2 = uVar1;
  iVar3 = core_globals_get();
  *(undefined1 *)(iVar3 + 2) = 8;
  iVar3 = core_globals_get();
  *(undefined2 *)(iVar3 + 4) = 0x800;
  iVar3 = core_globals_get();
  *(undefined4 *)(iVar3 + 8) = 0x7fff800;
  iVar3 = core_globals_get();
  memset((void *)(iVar3 + 0x1c),0,0x974);
  aps_dup_table_init(0x20);
  aps_group_table_init(0x10);
  aps_bind_table_init(0x10);
  aps_retrans_init();
  aps_reasm_init();
  iVar3 = core_globals_get();
  zmsg_queue_init(iVar3 + 0x2c);
  iVar3 = core_globals_get();
  iVar4 = core_globals_get();
  tasklet_init(iVar3 + 0x1c,aps_send_msg_task,iVar4 + 0x1c);
  return;
}

