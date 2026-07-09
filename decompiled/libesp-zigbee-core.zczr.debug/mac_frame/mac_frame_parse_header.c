/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac_frame.o -> mac_frame_parse_header
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int mac_frame_parse_header(undefined4 *param_1,int param_2,undefined1 *param_3)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  ushort *puVar4;
  
  if (param_1 == (undefined4 *)0x0) {
    iVar3 = 0;
    iVar2 = 2;
  }
  else if (param_2 == 0) {
    iVar3 = 0;
    iVar2 = 2;
  }
  else {
    iVar2 = mac_frame_validate_psdu();
    if (iVar2 == 0) {
      puVar4 = (ushort *)*param_1;
      uVar1 = *puVar4;
      *(ushort *)(param_2 + 0x18) = uVar1;
      iVar3 = mac_frame_get_seq_num(param_1,param_2 + 0x1a);
      if ((iVar3 == 0) || ((uVar1 & 0x3000) == 0x2000)) {
        iVar2 = mac_frame_get_dstaddr(param_1,param_2);
        if (iVar2 == 0) {
          iVar2 = mac_frame_get_srcaddr(param_1,param_2 + 10);
          if (iVar2 == 0) {
            iVar3 = mac_frame_get_dst_panid(param_1,param_2 + 0x14);
            if (iVar3 != 0) {
              *(undefined2 *)(param_2 + 0x14) = 0xffff;
            }
            iVar3 = mac_frame_get_src_panid(param_1,param_2 + 0x16);
            if (iVar3 != 0) {
              *(undefined2 *)(param_2 + 0x16) = *(undefined2 *)(param_2 + 0x14);
            }
            iVar3 = mac_frame_find_payload_index(param_1);
            if ((uVar1 & 7) == 3) {
              *(undefined1 *)(param_2 + 0x1b) = *(undefined1 *)((int)puVar4 + iVar3);
            }
            else {
              *(undefined1 *)(param_2 + 0x1b) = 0;
            }
          }
          else {
            iVar3 = 0;
          }
        }
        else {
          iVar3 = 0;
        }
      }
      else {
        iVar3 = 0;
        iVar2 = 0x10;
      }
    }
    else {
      iVar3 = 0;
    }
  }
  if (param_3 != (undefined1 *)0x0) {
    *param_3 = (char)iVar3;
  }
  return iVar2;
}

