/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libzboss_port.remote.debug -> zb_esp_osif.o -> zb_esp_clr_event
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void zb_esp_clr_event(int param_1)

{
  ssize_t sVar1;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_18 = 0;
  uStack_14 = 0;
  sVar1 = read(param_1,&uStack_18,8);
  if (sVar1 == 8) {
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zboss/components/zboss_port/src/zb_esp_osif.c",0x55,
                "zb_esp_clr_event","ret == sizeof(event_read)");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

