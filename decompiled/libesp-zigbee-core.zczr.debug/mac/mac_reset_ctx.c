/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_reset_ctx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_reset_ctx(int param_1)

{
  memset((void *)(param_1 + 0x2c),0,0x74);
  *(undefined1 *)(param_1 + 0x2e) = 0;
  *(undefined1 *)(param_1 + 0x32) = 0xff;
  *(undefined1 *)(param_1 + 0x41) = 0xb;
  *(undefined1 *)(param_1 + 0x42) = 0;
  *(undefined1 *)(param_1 + 0x43) = 0xff;
  *(undefined1 *)(param_1 + 0x44) = 0xff;
  tasklet_init(param_1 + 0x7c,mac_tasklet_func_wrapper,param_1);
  micro_timer_init(param_1 + 0x8c,mac_timer_func_wrapper,param_1);
  zmsg_queue_init(param_1 + 0x48);
  micro_timer_init(param_1 + 0x6c,mac_handle_transaction_timeout,param_1);
  zmsg_queue_init(param_1 + 0x54);
  zmsg_queue_init(param_1 + 0x60);
  mac_pal_src_match_reset();
  return;
}

