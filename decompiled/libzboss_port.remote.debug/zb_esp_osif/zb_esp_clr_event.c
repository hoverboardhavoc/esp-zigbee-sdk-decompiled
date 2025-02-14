/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
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
  undefined4 in_stack_00000074;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_18 = 0;
  uStack_14 = 0;
  sVar1 = read(param_1,&uStack_18,8);
  if (sVar1 == 8) {
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zboss/components/zboss_port/src/zb_esp_osif.c",0x55,
                "zb_esp_clr_event",0x100ac);
  tp = in_stack_00000074;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

