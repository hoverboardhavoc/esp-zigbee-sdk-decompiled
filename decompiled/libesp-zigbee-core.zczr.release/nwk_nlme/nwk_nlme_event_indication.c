/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_nlme.o -> nwk_nlme_event_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_nlme_event_indication(char *param_1)

{
  char cVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  
  if (*param_1 != '\0') {
    if (*param_1 == '\x01') {
      log_write(3,"nwk_nlme.c","Permit Joining: duration %d",param_1[2]);
      return;
    }
    param_1 = (char *)__assert_func(0,0,0,0);
  }
  cVar1 = param_1[2];
  uVar2 = *(undefined2 *)(param_1 + 4);
  uVar3 = nwk_network_status_to_str(cVar1);
  log_write(3,"nwk_nlme.c","NWK Status Indication: %s (0x%02x), addr 0x%04x",uVar3,cVar1,uVar2);
  return;
}

