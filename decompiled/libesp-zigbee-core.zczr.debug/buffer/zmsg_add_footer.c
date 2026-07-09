/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> zmsg_add_footer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zmsg_add_footer(int param_1,void *param_2,size_t param_3)

{
  uint uVar1;
  uint uVar2;
  void *__dest;
  int unaff_s3;
  
  uVar1 = *(ushort *)(param_1 + 0x10) + param_3;
  uVar2 = uVar1 & 0xffff;
  if (uVar2 < 0xad) {
    unaff_s3 = zmsg_resize(*(ushort *)(param_1 + 0xe) + param_3 & 0xffff);
    if (unaff_s3 != 0) {
      return unaff_s3;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/buffer.c",0x172,
                  "zmsg_add_footer","new_tail_len <= (176 - sizeof(struct buf_hdr_s))");
  }
  *(short *)(param_1 + 0x10) = (short)(uVar1 * 0x10000 >> 0x10);
  buffers_get_last(*(undefined4 *)(param_1 + 8));
  __dest = (void *)buffer_get_tail(uVar2);
  memcpy(__dest,param_2,param_3);
  return unaff_s3;
}

