/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_cb_address_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

undefined4 zdo_cb_address_rsp(int param_1,int param_2)

{
  if ((param_1 != 0) && (param_2 != 0)) {
    zdo_packet_notify_result(param_2,0);
    return 0;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_dev_srv_disc.c",0x1c9,
                "zdo_cb_address_rsp","rsp && ctx");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

