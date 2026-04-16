/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> time.o -> zcl_time_server_sync_finished
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zcl_time_server_sync_finished(void *user_ctx)

{
  undefined4 uVar1;
  zcl_attr_desc_t *pzVar2;
  byte abStack_11 [4];
  uint8_t time_status;
  
  milli_timer_stop((int)user_ctx + 0xc);
  if (*(int *)((int)user_ctx + 0x20) != -1) {
    pzVar2 = time_server_get_attr_desc(*(uint8_t *)((int)user_ctx + 0x25),1);
                    /* WARNING: Load size is inaccurate */
    abStack_11[0] = *pzVar2->data_p | 2;
    zcl_set_attr_value(*(undefined1 *)((int)user_ctx + 0x25),10,1,0,abStack_11,0);
  }
  if (*(code **)((int)user_ctx + 8) != (code *)0x0) {
    if (*(int *)((int)user_ctx + 0x20) == -1) {
      uVar1 = 7;
    }
    else {
      uVar1 = 0;
    }
    (**(code **)((int)user_ctx + 8))(uVar1);
  }
  return;
}

