/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> metering.o -> parse_block_info_set_from_payload
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int parse_block_info_set_from_payload(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = zcl_packet_read_variable_attr_value(0x25,param_3);
  if (iVar1 == 6) {
    iVar1 = af_read_le32(param_1,param_2,param_3 + 8);
    if (iVar1 == 4) {
      iVar1 = af_read_le32(param_1,param_2,param_3 + 0xc);
      if (iVar1 == 4) {
        iVar1 = af_read_le32(param_1,param_2,param_3 + 0x10);
        if (iVar1 == 4) {
          iVar1 = af_read_le32(param_1,param_2,param_3 + 0x14);
          if (iVar1 == 4) {
            iVar1 = af_read_le8(param_1,param_2,param_3 + 0x18);
            if (iVar1 == 1) {
              iVar1 = af_read_le8(param_1,param_2,param_3 + 0x19);
              if (iVar1 == 1) {
                iVar1 = parse_summation_from_payload
                                  (param_1,param_2,*(undefined1 *)(param_3 + 0x19),param_3 + 0x1c);
                if (iVar1 == 0) {
                  iVar1 = af_read_le8(param_1,param_2,param_3 + 0x20);
                  if (iVar1 == 1) {
                    iVar1 = parse_summation_from_payload
                                      (param_1,param_2,*(undefined1 *)(param_3 + 0x20),
                                       param_3 + 0x24);
                  }
                  else {
                    iVar1 = 0x80;
                  }
                }
              }
              else {
                iVar1 = 0x80;
              }
            }
            else {
              iVar1 = 0x80;
            }
          }
          else {
            iVar1 = 0x80;
          }
        }
        else {
          iVar1 = 0x80;
        }
      }
      else {
        iVar1 = 0x80;
      }
    }
    else {
      iVar1 = 0x80;
    }
  }
  else {
    iVar1 = 0x80;
  }
  return iVar1;
}

