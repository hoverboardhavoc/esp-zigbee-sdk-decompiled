/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> af_core.o -> af_data_indication_deliver_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void af_data_indication_deliver_handler(int param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/af/af_core.c",0xad,
                  "af_data_indication_deliver_handler",0x102dc);
  }
  else {
    if (*(char *)(param_1 + 7) != -1) {
      af_data_indication_handler();
      return;
    }
    uVar2 = 0;
    pcVar1 = (char *)0x0;
    while (pcVar1 = (char *)af_device_get_next_endpoint_desc(pcVar1), pcVar1 != (char *)0x0) {
      if ((*pcVar1 != -1) && (*(short *)(pcVar1 + 2) == *(short *)(param_1 + 10))) {
        af_data_indication_deliver_ep(param_1,uVar2);
        uVar2 = random_add_jitter(uVar2,10);
      }
    }
  }
  zmsg_free(*(undefined4 *)(param_1 + 0x10));
  return;
}

