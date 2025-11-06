/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libzboss_port.remote.debug -> zb_esp_osif.o -> zb_esp_set_event
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void zb_esp_set_event(int param_1)

{
  ssize_t sVar1;
  int iStack_18;
  int iStack_14;
  
  iStack_14 = param_1 >> 0x1f;
  iStack_18 = param_1;
  sVar1 = write(param_1,&iStack_18,8);
  if (sVar1 == 8) {
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zboss/components/zboss_port/src/zb_esp_osif.c",0x4e,
                "zb_esp_set_event",0x10000);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

