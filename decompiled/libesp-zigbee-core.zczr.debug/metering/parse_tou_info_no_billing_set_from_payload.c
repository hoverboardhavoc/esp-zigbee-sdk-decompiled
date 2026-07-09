/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> metering.o -> parse_tou_info_no_billing_set_from_payload
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
parse_tou_info_no_billing_set_from_payload(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = zcl_packet_read_variable_attr_value(0x25,param_3);
  if (iVar1 == 6) {
    iVar1 = af_read_le8(param_1,param_2,param_3 + 8);
    if (iVar1 == 1) {
      uVar2 = parse_summation_from_payload
                        (param_1,param_2,*(undefined1 *)(param_3 + 8),param_3 + 0xc);
    }
    else {
      uVar2 = 0x80;
    }
  }
  else {
    uVar2 = 0x80;
  }
  return uVar2;
}

